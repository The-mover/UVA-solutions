/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull dp[65][65];

ull trib(int n, int bak) {
    if( n <= 1 ) return 1;
    if( dp[n][bak] ) return dp[n][bak];

    ull ret = 1;

    for(int i=1; i<=bak; i++) {
        ret += trib(n-i, bak);
    }
    return dp[n][bak] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int n, m, t = 0;
    memset(dp, 0, sizeof dp);
    while( scanf("%d %d", &n, &m) == 2 ) {
        if( n > 61 || m > 60 ) break;
        printf("Case %d: %llu\n", ++t, trib(n, m));
    }

    return 0;
}
