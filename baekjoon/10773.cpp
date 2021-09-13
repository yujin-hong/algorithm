#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        if(tmp==0) {
            st.pop();
        } else {
            st.push(tmp);
        }
    }
    int ans = 0;
    while(!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }
    cout<<ans<<'\n';

}