#include <iostream>
#include <bits/stdc++.h>

using namespace std;

deque<int> deq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        string s;
        cin>>s;
        if(s=="push_front") {
            int tmp;
            cin>>tmp;
            deq.push_front(tmp);
        } else if (s=="push_back") {
            int tmp;
            cin>>tmp;
            deq.push_back(tmp);
        } else if (s=="pop_front") {
            if(deq.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<deq.front()<<'\n';
                deq.pop_front();
            }
        } else if (s=="pop_back") {
            if(deq.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<deq.back()<<'\n';
                deq.pop_back();
            }
        } else if (s=="size") {
            cout<<deq.size()<<'\n';
        } else if (s=="empty") {
            cout<<deq.empty()<<'\n';
        } else if (s=="front") {
            if(deq.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<deq.front()<<'\n';
            }
        } else if (s=="back") {
            if(deq.empty()) {
                cout<<"-1"<<'\n';
            } else {
                cout<<deq.back()<<'\n';
            }
        }

    }

}