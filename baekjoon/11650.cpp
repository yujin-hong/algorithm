#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;
int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int a, b;
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<num;i++) {
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }
}