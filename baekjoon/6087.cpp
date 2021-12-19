#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int n,m;
char arr[101][101];
int visited[101][101];
pair<int, int> st;
pair<int, int> en;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_coord(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n;
}
int bfs() {
    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = 1;
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        vector<pair<int, int>> v;
        // cout<<"step: "<<step<<'\n';
        for(int i=0;i<qsize;i++) {
            auto [tx, ty] = q.front(); q.pop();
            // cout<<tx<<' '<<ty<<'\n';
            if(tx == en.first && ty == en.second) {
                return step;
            }
            for(int j=0;j<4;j++) {
                int px = tx+dx[j];
                int py = ty+dy[j];
                while(check_coord(px, py) && visited[px][py] == 0 && arr[px][py] != '*') {
                    v.push_back(make_pair(px, py));
                    q.push(make_pair(px, py));
                    // visited[px][py] = 1;
                    px += dx[j];
                    py += dy[j];
                }
            }
        }
        for(int i=0;i<v.size();i++) {
            auto [tx, ty] = v[i];
            visited[tx][ty] = 1;
        }
        // cout<<"============="<<'\n';
        step++;
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>m;
    vector<pair<int, int>> v;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'C') {
                v.push_back(make_pair(i, j));
            }
        }
    }
    st = v[0];
    en = v[1];
    cout<<bfs()-1<<'\n';
}