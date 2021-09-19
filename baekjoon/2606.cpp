#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> v[101];
queue<int> q;
int visited[101];
int ans = -1;
void bfs() {
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int front = q.front();
        // cout<<front<<'\n';
        q.pop();
        ans++;
        for(int i=0;i<v[front].size();i++) {
            if(visited[v[front][i]]==0) {
                visited[v[front][i]]=1;
                q.push(v[front][i]);
            }
        }
    }
    return;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    int tc_num;
    cin>>num>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int m, n;
        cin>>m>>n;
        v[m].push_back(n);
        v[n].push_back(m);
    }
    bfs();
    cout<<ans<<'\n';
}