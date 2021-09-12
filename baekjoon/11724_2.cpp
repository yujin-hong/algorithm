#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];
int visited[1001] = {0,};

void bfs(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        vector<int> candidates = v[front];
        for(int i=0;i<candidates.size();i++) {
            int this_point = candidates[i];
            if(visited[this_point] == 0) {
                visited[this_point] = 1;
                q.push(this_point);
            }
        }
    }

}

int main() {
    int ans = 0;
    freopen("input.txt","r",stdin);
    int point_count, tc_count;
    cin>>point_count>>tc_count;
    for(int i=0;i<tc_count;i++) {
        int m,n;
        cin>>m>>n;
        v[m].push_back(n);
        v[n].push_back(m);
    }
    for(int i=1;i<=point_count;i++) {
        if(visited[i] == 0) {
            bfs(i);
            ans++;
        }
    }
    cout<<ans<<'\n';
}