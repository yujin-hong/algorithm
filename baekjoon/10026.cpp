#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char arr[101][101];
int visited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int num;

bool check_coord(int x, int y) {
    return x>=0 && x<num && y>=0 && y<num;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    char ch = arr[x][y];
    while(!q.empty()) {
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int tx = sx + dx[i];
            int ty = sy + dy[i];
            if(check_coord(tx, ty) && visited[tx][ty]==0 && arr[tx][ty]==ch) {
                visited[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

void crazy_bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    char ch = arr[x][y];
    while(!q.empty()) {
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int tx = sx + dx[i];
            int ty = sy + dy[i];
            if(check_coord(tx, ty) && visited[tx][ty]==0) {
                if(ch=='R' || ch=='G') {
                    if(arr[tx][ty]=='R' || arr[tx][ty]=='G') {
                        visited[tx][ty] = 1;
                        q.push(make_pair(tx, ty));
                    }
                } else if(ch=='B') {
                    if(arr[tx][ty]==ch) {
                        visited[tx][ty] = 1;
                        q.push(make_pair(tx, ty));
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cin>>arr[i][j];
        }
    }
    int ans1=0;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            if(visited[i][j]==0) {
                bfs(i, j);
                ans1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    int ans2=0;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            if(visited[i][j]==0) {
                crazy_bfs(i, j);
                ans2++;
            }
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
}