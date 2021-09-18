#include <iostream>
#include <bits/stdc++.h>

using namespace std;

set<string> st;
vector<string> v;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int a,b;
    int ans = 0;
    cin>>a>>b;
    for(int i=0;i<a+b;i++) {
        string s;
        cin>>s;
        if(st.count(s)!=0) {
            ans++;
            v.push_back(s);
        } else {
            st.insert(s);
        }
    }
    cout<<ans<<'\n';
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<'\n';
    }
}