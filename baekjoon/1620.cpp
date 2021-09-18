#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string, string> m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num, tc_num;
    cin>>num>>tc_num;
    for(int i=1;i<=num;i++) {
        string s;
        cin>>s;
        m[s]=to_string(i);
        m[to_string(i)] = s;
    }
    for(int i=0;i<tc_num;i++) {
        string s;
        cin>>s;
        cout<<m[s]<<'\n';
    }
}