#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;

queue<pair<int, int>> q;

bool check_coord(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n && arr[x][y]==1;

}

void bfs(int sx, int sy) {
    q.push(make_pair(sx, sy));
    visited[sx][sy]=1;
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int tx = front.first + dx[i];
            int ty = front.second + dy[i];
            if(check_coord(tx, ty) && visited[tx][ty]==0) {
                q.push(make_pair(tx, ty));
                visited[tx][ty] = 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        int row_num;
        cin>>m>>n>>row_num;
        for(int j=0;j<row_num;j++) {
            int a, b;
            cin>>a>>b;
            arr[a][b] = 1;
        }
        for(int p=0;p<m;p++) {
            for(int q=0;q<n;q++) {
                if(arr[p][q]==1 && visited[p][q]==0) {
                    bfs(p, q);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    
}