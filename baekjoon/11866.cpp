#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int main() {
    int num, mod_num;
    cin>>num>>mod_num;
    for(int i=1;i<=num;i++) {
        q.push(i);
    }
    cout<<"<";
    int add_num = 1;
    while(!q.empty()) {
        int top = q.front();
        // cout<<top<<' ';
        if(add_num%mod_num!=0) {
            q.push(top);
        } else {
            if(q.size()==1) {
                cout<<top<<">";
            } else {
                cout<<top<<", ";
            }
        }
        add_num++;
        q.pop();
    }
    cout<<"\n";
    
}