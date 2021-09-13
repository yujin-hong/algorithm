#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;
int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int fl = 0;
        stack<int> st;
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='(') {
                st.push(1);
            } else {
                if(st.empty()) {
                    fl = 1;
                    break;
                }
                st.pop();
            }
        }
        if(fl==1 || !st.empty()) {
            cout<<"NO"<<'\n';
        } else {
            cout<<"YES"<<'\n';
        }
    }

}