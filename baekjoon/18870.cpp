#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
map<int, int> m;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    vector<int> v1 = v;
    sort(v1.begin(), v1.end());
    int inst_num = 0;
    for(int i=1;i<v1.size();i++) {
        if(v1[i-1]!=v1[i]) {
            inst_num++;
            m[v1[i]] = inst_num;
        }
    }
    for(int i=0;i<v.size();i++) {
        cout<<m[v[i]]<<' ';
    }
    cout<<'\n';

}