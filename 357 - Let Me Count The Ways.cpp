/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;
const int M = 1e9 + 7;

int ara[6] = {1, 5, 10, 25, 50};
int x, n = 5;

ll dp[6][30005];

ll rec(int i, int sum) {
    if( i == n || sum < 0 ) return 0;
    if( sum == 0 ) return 1;
    if( dp[i][sum] != -1 ) return dp[i][sum];
    ll ret = 0;
    ret += rec(i, sum - ara[i]) + rec(i+1, sum);
    return dp[i][sum] = ret;
}


int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    memset(dp, -1, sizeof dp);
    while( scanf("%d", &x) == 1 ) {
        ll ans = rec(0, x);
        if( ans > 1 ) {
            printf("There are %lld ways to produce %d cents change.\n", ans, x);
        }
        else {
            printf("There is only 1 way to produce %d cents change.\n", x);
        }
    }

    return 0;
}
