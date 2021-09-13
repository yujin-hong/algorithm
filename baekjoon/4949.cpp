#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    while(true) {
        stack<char> st;
        string s;
        int fl = 1;
        getline(cin, s);
        // cin>>s;
        if(s==".") {
            break;
        }
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')'){
                if(st.empty()) {
                    fl=0;
                    break;
                }                
                if(st.top() == '(') {
                    st.pop();
                } else {
                    fl=0;
                    break;
                }
            } else if (s[i] == ']'){
                if(st.empty()) {
                    fl=0;
                    break;
                }
                if(st.top() == '[') {
                    st.pop();
                } else {
                    fl=0;
                    break;
                }
            }
        }
        if(fl==0 || !st.empty()) {
            cout<<"no"<<'\n';
        } else {
            cout<<"yes"<<'\n';
        }
    }
}