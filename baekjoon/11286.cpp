#include <iostream>
#include <bits/stdc++.h>

using namespace std;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        if(tmp==0) {
            if(pq.empty()) {
                cout<<0<<'\n';
            } else {
                cout<<pq.top().second<<'\n';
                pq.pop();
            }
        } else {
            pq.push(make_pair(abs(tmp), tmp));
        }

    }

}