/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std ;

typedef long long ll;

int a, b, t;
int ara[4];
int dp[3][10005];
int dp1[10005];

/**
    * first we will run a dp for maximizing the time of eating burger;
**/

int fun(int i, int w) {
    if(i == 3) {
        return 0;
    }
    if(dp[i][w] != -1) {
        return dp[i][w];
    }
    int c = 0, d = 0;
    if( w + ara[i] <= t ) {
        c = ara[i] + fun(i, w + ara[i]);
    }
    if( w + ara[i] <= t ) {
        d = ara[i] + fun(i+1, w + ara[i]);
    }
    int e = fun(i+1, w);
    int ret = max({c, d, e});
    return dp[i][w] = ret;
}

/**
    * here in 2nd dp we will maximize the burger he can eat
**/

int rec(int n) {
    if( n < 0 ) {
        return -INT_MAX;
    }
    if( n == 0 ) {
        return 0;
    }
    if( dp1[n] != -1 ) {
        return dp1[n];
    }
    int ret = -INT_MAX;
    ret = max(ret, 1 + rec(n - a));
    ret = max(ret, 1 + rec(n - b));
    return dp1[n] = ret;
}

int main()
{
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    while( cin >> a >> b >> t ) {
        memset(dp, -1, sizeof dp);
        memset(dp1, -1, sizeof dp1);
        ara[1] = a;
        ara[2] = b;
        int ans = fun(1, 0);
        //cout << "max_sum = " << ans << "\n";
        int rem = t - ans;
        int res = rec(t-rem);
        cout << res;
        if( rem ) {
            cout << " " << rem;
        }
        cout << "\n";
    }

    return 0;
}


