#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> v[1001];

    int node_num, line_num, start_node;
    cin>>node_num>>line_num>>start_node;
    for(int i=0;i<line_num;i++) {
        int s, e;
        cin>>s>>e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    bfs(start_node);
    dfs(start_node);
}

void dfs(int start_node) {
    int visited[4];
    cout<<start_node<<'\n';

}

void bfs(int start_node) {

}