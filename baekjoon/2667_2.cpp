#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> v;
int visited[26][26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int row_num;

vector<int> each_count;

bool check_coord(int x, int y) {
    return x>=0 && x<row_num && y>=0 && y<row_num && v[x][y] == '1';
}

void bfs(pair<int, int> st) {
    int count = 0;
    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = 1;
    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        count++;
        for(int i=0;i<4;i++) {
            int tx = front.first + dx[i];
            int ty = front.second + dy[i];
            if(check_coord(tx, ty) && visited[tx][ty] == 0) {
                visited[tx][ty] = 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
    each_count.push_back(count);
}

int main() {
    int ans = 0;
    freopen("input.txt","r",stdin);
    cin>>row_num;
    for(int i=0;i<row_num;i++) {
        vector<char> tmp;
        for(int j=0;j<row_num;j++) {
            char ch;
            cin>>ch;
            tmp.push_back(ch);
        }
        v.push_back(tmp);
    }
    for(int i=0;i<row_num;i++) {
        for(int j=0;j<row_num;j++) {
            if(v[i][j] == '1' && visited[i][j] == 0) {
                bfs(make_pair(i,j));
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    sort(each_count.begin(), each_count.end());
    for(int i=0;i<each_count.size();i++) {
        cout<<each_count[i]<<'\n';
    }
}