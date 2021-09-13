#include <iostream>
#include <bits/stdc++.h>

using namespace std;

queue<int> q;
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
            q.push(tmp);
        } else if (s=="pop") {
            if(q.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<q.front()<<'\n';
                q.pop();
            }
        } else if (s=="size") {
            cout<<q.size()<<'\n';
        } else if (s=="empty") {
            cout<<q.empty()<<'\n';
        } else if (s=="front") {
            if(q.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<q.front()<<'\n';
            }
        } else if (s=="back") {
            if(q.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<q.back()<<'\n';
            }
        }

    }

}