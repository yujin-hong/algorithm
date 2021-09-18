#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string, string> m;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++) {
        string key, val;
        cin>>key>>val;
        m[key] = val;
    }
    for(int i=0;i<b;i++) {
        string ques;
        cin>>ques;
        cout<<m[ques]<<'\n';
    }

}