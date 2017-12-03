/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, int> ara[1005];
int dp[1001][1001];
int cap, n;

int rec(int i, int w) {
    if( i == n + 1 ) {
        return 0;
    }
    if( dp[i][w] != -1 ) {
        return dp[i][w];
    }
    int a = 0;
    if( ara[i].second + w <= cap ) {
        a = ara[i].first + rec(i+1, w+ara[i].second);
    }
    else a = 0;
    int b = rec(i+1, w);
    dp[i][w] = max(a, b);
    return dp[i][w];
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t;
    cin >> t;
    while( t-- ) {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> ara[i].first >> ara[i].second;
        }
        int g, sum = 0;
        cin >> g;
        for(int i=1; i<=g; i++) {
            cin >> cap;
            memset(dp, -1, sizeof dp);
            sum += rec(1, 0);
        }
        cout << sum << "\n";
    }

    return 0;
}
