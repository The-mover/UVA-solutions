/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int M = 1e9 + 7;

int ss, n, ara[22];
map<int, int> dp[22];
vector<int> ve;

int rec(int i, int sum) {
    if( i == n ) return sum;
    int ret = 0;
    if( dp[i].count(sum) ) return dp[i][sum];
    ret = 0;
    if( sum + ara[i] <= ss ) {
        ret = max(ret, rec(i+1, sum+ara[i]));
    }
    ret = max(ret, rec(i+1, sum));
    return dp[i][sum] = ret;
}

void print(int i, int sum) {
    if( i == n ) return;
    int ret = dp[i][sum];
    if( ret == rec(i+1, sum+ara[i]) ) {
        ve.push_back(ara[i]);
        print(i+1, sum+ara[i]);
    }
    else print(i+1, sum);
}

int main() {
    #ifdef _OFFLINE_
        freopen("A.txt", "r", stdin);
    #endif /// _OFFLINE_

    while( cin >> ss ) {
        //cerr << ss << "\n";
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> ara[i];
        }
        for(int i=0; i<22; i++) {
            dp[i].clear();
            //cout << i << "\n";
        }
        //cerr << "done " << "\n";
        int ans = rec(0, 0);
        ve.clear();
        print(0, 0);
        //cout << ans << "\n\n";
        for(int i=0; i<ve.size(); i++) {
            cout << ve[i] << " ";
        }
        cout << "sum:" << ans << "\n";
    }

    return 0;
}
