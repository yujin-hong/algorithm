#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[2][100001];
int visited[2][100001];
queue<pair<int, int>> q;
int len, c;
int step = 0;

bool check_coord(int x, int y) {
    if(y>=len) return true;
    return x>=0 && x<2 && y>0 && y<100001 && arr[x][y]==1 && visited[x][y]==0;
}
int bfs(int x, int y) {
    visited[x][y] =1;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        int qsize = q.size();
        visited[0][step] = 1;
        visited[1][step] = 1;
        for(int i=0;i<qsize;i++) {
            int sx = q.front().first;
            int sy = q.front().second;
            // cout<<sx<<' '<<sy<<'\n';
            if(sy>=len) {
                return 1;
            }
            q.pop();
            if(check_coord(sx, sy+1)) {
                q.push(make_pair(sx, sy+1));
                visited[sx][sy+1] = 1;
            }
            if(check_coord(sx, sy-1)) {
                q.push(make_pair(sx, sy-1));
                visited[sx][sy-1] = 1;
            }
            if(check_coord(!sx, sy+c)) {
                q.push(make_pair(!sx, sy+c));
                visited[!sx][sy+c] = 1;
            }
        }
        step++;
    }
    return 0;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    cin>>len>>c;
    for(int i=0;i<2;i++) {
        for(int j=0;j<len;j++) {
            char ch;
            cin>>ch;
            arr[i][j] = ch-'0';
        }
    }
    cout<<bfs(0,0)<<'\n';
}