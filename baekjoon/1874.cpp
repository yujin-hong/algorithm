#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> s;
vector<char> ans;
int main() {
    freopen("input.txt","r",stdin);
    int num;
    int st = 1;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        for(int j=st;j<=tmp;j++) {
            s.push(j);
            ans.push_back('+');
            st++;
        }
        // cout<<s.top()<<' '<<tmp<<'\n';
        if(s.top() == tmp) {
            s.pop();
            ans.push_back('-');
        } else {
            cout<<"NO"<<'\n';
            return 0;
        }
    }
    if(!s.empty()) {
        cout<<"NO"<<'\n';
        return 0;
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<'\n';
    }
}