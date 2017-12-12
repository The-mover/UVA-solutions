/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;
const int M = 1e9 + 7;

int target, n, coins[105];
int dp[104][10004];
int bd[104][10004];

int rec(int i, int sum) {
    //cerr << "sum = " << sum << "\n";
    if(sum >= target ) return sum;
    if(i == n) return INT_MAX;
    if( dp[i][sum] != -1 ) return dp[i][sum];
    int ret = INT_MAX;
    ret = min(ret, rec(i+1, sum + coins[i]));
    ret = min(ret, rec(i+1, sum));
    return dp[i][sum] = ret;
}

int fun(int i, int sum) {
    if(sum == 0) return 0;
    if(sum < 0 ) return 9999999;
    if(i==n) return 9999999;
    if(bd[i][sum] != -1 ) return bd[i][sum];
    int ret = 9999999;
    ret = min(ret, 1 + fun(i + 1, sum - coins[i]));
    ret = min(ret, fun(i + 1, sum));
    return bd[i][sum] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t;
    scanf("%d", &t);
    while( t-- ) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &target);
        scanf("%d", &n);
        //cerr << target << " " << n << "\n";
        for(int i=0; i<n; i++) scanf("%d", &coins[i]);
        int sum = rec(0, 0);
        //cerr << sum << "\n";
        memset(bd, -1, sizeof bd);
        int ans = fun(0, sum);
        printf("%d %d\n", sum, ans);
    }

    return 0;
}
