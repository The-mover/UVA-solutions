/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005;
const int M = 1e9 + 7;

int coins[23] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
int m = 21, x;
ll dp[23][10002];
ll rec(int i, int sum) {
    //cerr << i << " " << sum << "\n";
    if( sum == 0 ) return 1;
    if(i == m ) return sum == 0;
    if( sum < 0 ) return 0;
    if( dp[i][sum] != -1ll ) return dp[i][sum];
    ll ret = 0;
    ret += rec(i, sum - coins[i]) + rec(i+1, sum);
    return dp[i][sum] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    memset(dp, -1, sizeof dp);
    while( scanf("%d", &x) == 1 ) {
//        cerr << x << "\n";
        ll ans = rec(0, x);
        printf("%lld\n", ans);
    }


    return 0;
}
