#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int visited[200001];
int main() {
    int count = 0;
    queue<int> q;
    freopen("input.txt","r",stdin);
    int m, n;
    cin>>m>>n;
    q.push(m);
    visited[m] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            int front = q.front();
            if(front == n) {
                cout<<count<<'\n';
                return 0;
            }
            q.pop();
            int tx = front + 1;
            if(tx>=0 && tx<200001 && visited[tx] == 0) {
                visited[tx] = 1;
                q.push(tx);
            }
            tx = front - 1;
            if(tx>=0 && tx<200001 && visited[tx] == 0) {
                visited[tx] = 1;
                q.push(tx);
            }
            tx = front*2;
            if(tx>=0 && tx<200001 && visited[tx] == 0) {
                visited[tx] = 1;
                q.push(tx);
            }
        }
        count++;
    }
}