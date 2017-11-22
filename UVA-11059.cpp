/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, ara[20];
set<ll> st;

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    while( scanf("%lld", &n) == 1 ) {
        for(int i=1; i<=n; i++) {
            scanf("%lld", &ara[i]);
        }
        st.clear();
        st.insert(0);
        for(int i=1; i<=n; i++) {
            ll prod = ara[i];
            if(prod >= 0) {
                st.insert(-prod);
            }
            for(int j=i+1; j<=n; j++) {
                prod *= ara[j];
                if(prod >= 0) {
                    st.insert(-prod);
                }
            }
        }
        ll ans = -*st.begin();

        printf("Case #%lld: The maximum product is %lld.\n\n", ++k, ans);
    }

    return 0;
}
