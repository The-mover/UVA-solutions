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

ll dp[6][8000];

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
    while( cin >> x ) {
        ll ans = rec(0, x);
        cout << ans << "\n";
    }

    return 0;
}
