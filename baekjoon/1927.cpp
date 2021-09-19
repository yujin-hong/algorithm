#include <iostream>
#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        long long tmp;
        cin>>tmp;
        if(tmp==0) {
            if(pq.empty()) {
                cout<<0<<'\n';
            } else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }

}