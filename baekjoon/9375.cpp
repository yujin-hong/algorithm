#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// long long ans = 0;

// void calc(int st, long long accum_multiple, vector<int> &v) {
//     if(st >= v.size()) {
//         ans = ans + accum_multiple;
//         return;
//     }
//     if(v[st]==0) {
//         return;
//     }
//     calc(st+1, accum_multiple, v);
//     if(accum_multiple == 0) {
//         calc(st+1, v[st], v);
//     } else {
//         calc(st+1, accum_multiple*v[st], v);
//     }
// }

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        vector<int> v;
        map<string, int> m;
        int row_num;
        cin>>row_num;
        for(int j=0;j<row_num;j++) {
            string el, type;
            cin>>el>>type;
            m[type]++;
        }
        long long ans = 1;
        for(auto it = m.begin(); it!=m.end();it++) {
            ans = ans * ((it->second)+1);
        }
        // calc(0, 0, v);
        cout<<ans-1<<'\n';
    }
    
}