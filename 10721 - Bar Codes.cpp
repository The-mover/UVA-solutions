/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[52][52];
int target, len, limit;

ll rec(int taken, int sum) {
    if(taken == len && sum == target) return 1;
    if(taken > len || sum > target ) return 0;
    if( dp[taken][sum] != -1 ) return dp[taken][sum];
    ll ret = 0;
    for(int i=1; i<=limit; i++) {
        if( sum + i <= target ) ret += rec(taken+1, sum+i);
        else break;
    }
    return dp[taken][sum] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    while( scanf("%d %d %d", &target, &len, &limit) == 3 ) {
        memset(dp, -1, sizeof dp);
        ll ans = rec(0, 0);
        printf("%lld\n", ans);
    }

    return 0;
}
