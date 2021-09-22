#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char arr[21][21];
int visited[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int char_check[27];
int n, m;
int max_num = INT_MIN;
bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int calc_char_count() {
    int sum =0;
    for(int i=0;i<27;i++) {
        if(char_check[i]==1) {
            sum++;
        }
    }
    return sum;
}
void dfs(int x, int y) {
    int fl = 0;
    visited[x][y] = 1;
    char_check[arr[x][y]-'A'] = 1;
    for(int i=0;i<4;i++) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(check_coord(tx, ty) && visited[tx][ty]==0 && char_check[arr[tx][ty]-'A']==0) {
            fl = 1;
            dfs(tx, ty);
        }
    }
    if(fl==0) {
        int now_size = calc_char_count();
        max_num = max(max_num, now_size);
    }
    visited[x][y] = 0;
    char_check[arr[x][y]-'A'] = 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    dfs(0, 0);
    cout<<max_num<<'\n';
}