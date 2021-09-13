#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<tuple<int, int, string>> v;

int main() {
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        string name;
        cin>>tmp>>name;
        v.push_back(make_tuple(tmp, i, name));
    }
    sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), greater<tuple<int, int, string>>());
    for(int i=0;i<v.size();i++) {
        cout<<get<0>(v[i])<<' '<<get<2>(v[i])<<'\n';
    }
}
