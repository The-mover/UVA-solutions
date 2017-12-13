/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int coins[202], n, q, d, m, t;
ll dp[202][11][50];

ll rec(int i, int taken, int sum) {
    if( taken == m && sum % d == 0 ) return 1;
    if( i == n ) return 0;
    if( taken > m ) return 0;
    if( dp[i][taken][sum] != -1 ) return dp[i][taken][sum];
    ll ret = 0;
    ret = rec(i+1, taken+1, (sum + coins[i]) % d) + rec(i+1, taken, sum % d);
    return dp[i][taken][sum] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
        //freopen("ou.txt", "w", stdout);
    #endif /// _OFFLINE_

    while( scanf("%d %d", &n, &q) == 2 ) {
        if( n == 0 && q == 0 ) break;
        for(int i=0; i<n; i++) scanf("%d", &coins[i]);
        printf("SET %d:\n", ++t);
        for(int tc = 1; tc <= q; tc++ ) {
            memset(dp, -1, sizeof dp);
            scanf("%d %d", &d, &m);
            ll ans = rec(0, 0, 0);
            printf("QUERY %d: %lld\n", tc, ans);
        }
    }

    return 0;
}
