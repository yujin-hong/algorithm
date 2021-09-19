#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        priority_queue<int> high_pq;
        priority_queue<int, vector<int>, greater<int>> low_pq;

        map<int, int> m;
        int num;
        cin>>num;
        for(int j=0;j<num;j++) {
            char ch;
            int tmp;
            cin>>ch>>tmp;
            if(ch == 'I') {
                m[tmp]++;
                high_pq.push(tmp);
                low_pq.push(tmp);
            } else if(ch == 'D') {
                if(tmp == 1 && !high_pq.empty()) {
                    if(m[high_pq.top()]!=0) {
                        m[high_pq.top()]--;
                        high_pq.pop();
                    }
                } else if(tmp == -1 && !low_pq.empty()) {         
                    if(m[low_pq.top()]!=0) {
                        m[low_pq.top()]--;
                        low_pq.pop();
                    }                 
                }
                while(!high_pq.empty() && m[high_pq.top()]==0) {
                    high_pq.pop();
                }                
                while(!low_pq.empty() && m[low_pq.top()]==0) {
                    low_pq.pop();
                }
            }
        }
        if(high_pq.empty() || low_pq.empty()) {
            cout<<"EMPTY"<<'\n';
        } else if(m[high_pq.top()]==0 || m[low_pq.top()]==0) {
            cout<<"EMPTY"<<'\n';
        } else {
            cout<<high_pq.top()<<' '<<low_pq.top()<<'\n';
        }
    }
}