#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if( a.first == b.first )
        return a.second > b.second;
    return a.first < b.first;
}

vector <pair<int, int> > ve;

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
        //freopen("ou.txt", "w", stdout);
    #endif /// _OFFLINE_

    string s;
    int counter = 1;
    while( getline(cin, s) ) {
        int n = s.size();
        int ara[129];
        memset(ara, 0, sizeof ara);
        for(int i=0; i<n; i++) {
            int a = s[i] - ' ';
            ara[a]++;
        }

        ve.clear();

        for(int i=0; i<128; i++) {
            if(ara[i]) {
                ve.push_back(make_pair(ara[i], i+32));
            }
        }

        sort(ve.begin(), ve.end(), cmp);

        if( counter != 1 ) {
            cout << "\n";
        }
        counter++;

        for(int i=0; i<ve.size(); i++) {
            cout << ve[i].second << " " << ve[i].first << "\n";
        }
    }

	return 0;
}

