/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int len, n, ara[25], dp[22][202], weight;

int rec(int i, int w) {
    if( i == len + 1 ) {
        return 0;
    }
    if( dp[i][w] != -1 ) {
        return dp[i][w];
    }
    int a = 0;
    if( ara[i] + w <= weight ) {
        a = ara[i] + rec(i+1, w+ara[i]);
    }
    else a = 0;
    int b = rec(i+1, w);
    return dp[i][w] = max(a, b);
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t, cnt = 5;
    cin >> t;
    getchar();
    while( t-- ) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string p;
        int i=0;
        while(ss >> p) {
            istringstream sp(p);
            sp >> n;
            ara[++i] = n;
        }
        int sum = 0;
        len = i;
        for(int j=1; j<=i; j++) {
            sum += ara[j];
        }
        weight = sum / 2;
        memset(dp, -1, sizeof dp);
        int ans = rec(1, 0);
        puts(sum - (ans * 2) == 0 ? "YES" : "NO");
    }

    return 0;
}
