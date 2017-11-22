/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, int> > ve;
int n, m, a;
int ara[105];
multiset<int> st;

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        //cerr << n << " " << m << "\n";
        int ans = 0, cur = 0;
        st.clear();
        ve.clear();
        for(int i=0; i<n; i++) {
            cin >> ara[i];
            st.insert(-ara[i]);
            ve.push_back({ara[i], i});
        }
        for(int i=0; i<ve.size(); i++) {
            int x = -*st.begin();
            if(ve[i].first == x) {
                st.erase(st.begin());
                cur++;
                if(ve[i].second == m) {
                    ans = cur;
                    break;
                }
            }
            else {
                ve.push_back({ve[i].first, ve[i].second});
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
