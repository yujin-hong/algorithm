#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        vector<pair<int, vector<int>>> v;
        int n, m;
        cin>>n>>m;
        for(int j=0;j<m;j++) {
            int tmp;
            vector<int> tmp_v;
            cin>>tmp;
            for(int k=0;k<tmp;k++) {
                int t;
                cin>>t;
                tmp_v.push_back(t);
            }
            pair<int, vector<int>> tmp_pair = make_pair(tmp, tmp_v);
            v.push_back(tmp_pair);
        }
        sort(v.begin(), v.end());
        for(int j=0;j<v.size();j++) {
            pair<int, vector<int>> tmp_pair = v[j];
            cout<<tmp_pair.first<<' ';
            vector<int> tt = tmp_pair.second;
            for(int k=0;k<tt.size();k++) {
                cout<<tt[k]<<' ';
            }
            cout<<'\n';
        }
    }
}