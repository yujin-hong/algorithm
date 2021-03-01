#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[1001];
int visited[1002] = {0,};

void dfs(int start_node);
void bfs(int start_node);

int main(void) {
    freopen("input.txt","r",stdin);

    int node_num, line_num, start_node;
    cin>>node_num>>line_num>>start_node;
    for(int i=0;i<line_num;i++) {
        int s, e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for(int i=1;i<=node_num;i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(start_node);
    cout<<'\n';
    memset(visited, 0, sizeof(visited));
    bfs(start_node);
}

void dfs(int start_node) {
    visited[start_node] = 1;
    cout<<start_node<<' ';
    vector<int> connect_nodes = v[start_node];
    for(int i=0;i<connect_nodes.size();i++) {
        if(visited[connect_nodes[i]]==0) {
            visited[connect_nodes[i]] = 1;
            dfs(connect_nodes[i]);
        }
    }
}

void bfs(int start_node) {
    queue<int> q;
    visited[start_node] = 1;
    q.push(start_node);
    while(!q.empty()) {
        int front = q.front();
        cout<<front<<' ';
        q.pop();
        vector<int> connect_nodes = v[front];
        for(int i=0;i<connect_nodes.size();i++) {
            if(visited[connect_nodes[i]]==0) {
                q.push(connect_nodes[i]);
                visited[connect_nodes[i]] = 1;
            }
        }
    }
}