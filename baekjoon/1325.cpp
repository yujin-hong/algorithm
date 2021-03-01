#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[10001];
set<int> s;

int node_count, num;
map<int, vector<int>> m;
int bfs(int start);
int max_num = -1;
int visited[10001];
queue<int> q;

int main() {
    freopen("input.txt","r",stdin);
    cin>>node_count>>num;
    for(int i=0;i<num;i++) {
        int st, de;
        cin>>de>>st;
        v[st].push_back(de);
        s.insert(st);
    }
	for(auto it = s.begin(); it != s.end(); it++){
        memset(visited, 0, sizeof(visited));
        int step = bfs(*it);
        if(step>max_num) max_num = step;
        m[step].push_back(*it);
        // cout<<step<<' '<<*it<<'\n';
	}
    vector<int> ans = m[max_num];
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) {
        // cout<<max_num<<'\n';
        cout<<ans[i]<<' ';
    }
}

int bfs(int start) {
    q.push(start);
    visited[start] = 1;
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int front = q.front();
            q.pop();
            step++;
            for(int j=0;j<v[front].size();j++) {
                if(visited[v[front][j]]==0) {
                    q.push(v[front][j]);
                    visited[v[front][j]] = 1;
                }
            }
        }
    }
    return step;
}