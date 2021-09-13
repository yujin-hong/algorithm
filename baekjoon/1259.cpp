#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    while(true) {
        int fl = 0;
        string s;
        cin>>s;
        // cout<<"str: "<<s<<'\n';
        if(s=="0") {
            break;
        }
        for(int i=0;i<s.size()/2;i++) {
            if(s[i] != s[s.size()-i-1]) {
                cout<<"no"<<'\n';
                fl = 1;
                break;
            }
        }
        if(fl==0) {
            cout<<"yes"<<'\n';
        }
    }
}