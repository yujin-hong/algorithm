#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[51][51] = {0,};
int visited[51][51] = {0, };
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool check_coord(int x, int y, int m, int n) {
    return x>=0 && y>=0 && x<n && y<m && arr[x][y]==1;
}
void bfs(pair<int, int> p, int m, int n) {
    queue<pair<int, int>> q;
    visited[p.first][p.second] = 1;
    q.push(p);
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        visited[front.first][front.second] = 1;
        for(int i=0;i<8;i++) {
            int tx = front.first + dx[i];
            int ty = front.second + dy[i];
            if(visited[tx][ty] == 0 && check_coord(tx, ty, m, n)) {
                visited[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
}
int bfs_and_return_count(int m, int n) {
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 1 && visited[i][j] == 0) {
                bfs(make_pair(i,j), m, n);
                count++;
            }
        }
    }
    return count;
}
int main() {
    freopen("input.txt","r",stdin);
    while(true) {
        int m, n;
        cin>>m>>n;
        // cout<<m<<' '<<n<<'\n';
        if(m==0 && n==0) {
            break;
        }
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        cout<<bfs_and_return_count(m, n)<<'\n';
    }
}