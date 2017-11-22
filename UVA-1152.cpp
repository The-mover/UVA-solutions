/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

/// Meet in the middle algorithm used for this problem.
/// Using map will cause tle;
/// unorderd_map should be used;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[4004], b[4004], c[4004], d[4004];
unordered_map<int, int> mp;
int n;

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t;
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        }
        mp.clear();
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int x = a[i] + b[j];
                mp[x]++;
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int x = c[i] + d[j];
                cnt += mp[-x];
            }
        }
        if(tc != 1) {
            cout << "\n";
        }
        printf("%d\n", cnt);
    }

    return 0;
}
