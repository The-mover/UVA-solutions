/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, weight;
int dp[501][50001];
int ara[501];

int rec(int i, int w) {
    if( i == n+1 ) {
        return 0;
    }
    if( dp[i][w] != -1 ) {
        return dp[i][w];
    }
    int a = 0;
    if( ara[i] + w <= weight ) {
        a = ara[i] + rec( i+1, w + ara[i] );
    }
    else a = 0;
    int b = rec(i+1, w);
    dp[i][w] = max(a, b);
    return dp[i][w];
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
        freopen("ou.txt", "w", stdout);
    #endif /// _OFFLINE_

    int t;
    cin >> t;
    while( t-- ) {
        memset(dp, -1, sizeof dp);
        int sum = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> ara[i];
            sum += ara[i];
        }
        weight = sum/2;
        //cout << "sum = " << sum << "\n";
        int ans = rec(1, 0);
        cout << sum - (ans * 2) << "\n";
    }

    return 0;
}
