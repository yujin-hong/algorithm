#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<tuple<int, int, int>> v;
map<int, int> m;
int main() {
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a, b;
        cin>>a>>b;
        v.push_back(make_tuple(a, b, i));
    }
    sort(v.begin(), v.end(), greater<tuple<int, int, int>>());
    // for(int i=0;i<n;i++) {
    //     cout<<get<0>(v[i])<<' '<<get<1>(v[i])<<' '<<get<2>(v[i])<<'\n';
    // }

    for(int i=0;i<n;i++) {
        int count = 0;
        int ind = get<2>(v[i]);
        for(int j=0;j<i;j++) {
            if((get<0>(v[i]) < get<0>(v[j])) && (get<1>(v[i]) < get<1>(v[j]))) count++;
        }
        m[ind] = count+1;
        
    }
    for(int i=0;i<n;i++) {
        cout<<m[i]<<' ';
    }
    cout<<'\n';
}
