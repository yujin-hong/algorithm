#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        string s;
        cin>>s;
        if(s=="push") {
            int tmp;
            cin>>tmp;
            st.push(tmp);
        } else if (s=="pop") {
            if(st.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<st.top()<<'\n';
                st.pop();
            }
        } else if (s=="size") {
            cout<<st.size()<<'\n';
        } else if (s=="empty") {
            cout<<st.empty()<<'\n';
        } else if (s=="top") {
            if(st.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<st.top()<<'\n';
            }
        }

    }

}