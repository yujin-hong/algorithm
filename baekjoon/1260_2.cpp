#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
int visited[1001] = {0,};

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    while(!q.empty()) {
        int top = q.front();
        cout<<top<<' ';
        q.pop();
        vector<int> possible_points = v[top];
        for(int i=0;i<possible_points.size();i++) {
            if(visited[possible_points[i]]==0) {
                visited[possible_points[i]] = 1;
                q.push(possible_points[i]);
            }
        }
    }
}

void dfs(int st) {
    cout<<st<<' ';
    vector<int> possible_points = v[st];
    for(int i=0;i<possible_points.size();i++) {
        if(visited[possible_points[i]] == 0) {
            visited[possible_points[i]]=1;
            dfs(possible_points[i]);
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    int point_count, tc_count, start_point;
    cin>>point_count>>tc_count>>start_point;
    for(int i=0;i<tc_count;i++) {
        int m, n;
        cin>>m>>n;
        v[m].push_back(n);
        v[n].push_back(m);
    }
    for(int i=1;i<=point_count;i++) {
        sort(v[i].begin(), v[i].end());
    }
    visited[start_point] = 1;
    dfs(start_point);
    cout<<'\n';
    memset(visited, 0, sizeof(visited));
    bfs(start_point);
    cout<<'\n';
}