/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005;
const int M = 1e9 + 7;

int coins[27] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
int n = 26, total, l, s, t;
ll dp[26][26][680];

int rec(int i, int limit, int sum) {
    if(i == n) {
        if( sum == 0 && limit == l) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if(sum < 0) return 0;
    if(sum == s && limit == l) return 1;
    if(dp[i][limit][sum] != -1) return dp[i][limit][sum];
    int ret = 0;
    ret += rec(i+1, limit+1, sum-coins[i]) + rec(i+1, limit, sum);
    return dp[i][limit][sum] = ret;
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    while( scanf("%d %d", &l, &s) == 2 ) {
        memset(dp, -1, sizeof dp);
        if(!l && !s) break;
        int ans = 0;
        if(l < 27 && s < 352 ) ans = rec(0, 0, s);
        printf("Case %d: %d\n", ++t, ans);
    }

    return 0;
}
