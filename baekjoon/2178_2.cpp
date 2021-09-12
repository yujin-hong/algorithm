#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char arr[101][101];
int visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n;

bool check_coord(int tx, int ty) {
    return tx>= 0 && tx<m && ty>=0 && ty<n && arr[tx][ty]=='1';
}

int bfs(pair<int, int> p) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push(p);
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            pair<int, int> front = q.front();
            visited[front.first][front.second] = 1;
            q.pop();
            for(int i=0;i<4;i++) {
                int tx = front.first + dx[i];
                int ty = front.second + dy[i];
                if(check_coord(tx, ty) && visited[tx][ty] == 0) {
                    if(tx == m-1 && ty == n-1) {
                        return count;
                    }
                    visited[tx][ty] = 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }
        count++;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<bfs(make_pair(0, 0))+1<<'\n';
}