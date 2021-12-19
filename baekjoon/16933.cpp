#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int n, m, k;
int arr[1001][1001];
int visited[1001][1001][11][3];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int x, int y) {
    int step = 1;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, k));
    visited[x][y][k][0] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        int is_day = step%2;
        for(int p=0;p<qsize;p++) {
            auto [tx, ty, tk] = q.front(); q.pop();
            // cout<<tx<<' '<<ty<<' '<<tk<<' '<<is_day<<'\n';
            if(tx == n-1 && ty == m-1) {
                return step;
            }
            if(check_coord(tx, ty)) {
                if(visited[tx][ty][tk][is_day] == 0) {
                    visited[tx][ty][tk][is_day] = 1;
                    q.push(make_tuple(tx, ty, tk));
                }    
            }        
            for(int i=0;i<4;i++) {
                int px = tx + dx[i];
                int py = ty + dy[i];
                if(check_coord(px, py)) {
                    if(arr[px][py] == 0 && visited[px][py][tk][is_day] == 0) {
                        visited[px][py][tk][is_day] = 1;
                        q.push(make_tuple(px, py, tk));
                    }
                    if(is_day) {
                        if(arr[px][py] == 1 && tk-1>=0 && visited[px][py][tk-1][is_day] == 0) {
                            visited[px][py][tk-1][is_day] = 1;
                            q.push(make_tuple(px, py, tk-1));
                        }
                    }
                    // cout<<px<<' '<<py<<' '<<tk<<'\n';
                    // cout<<arr[px][py]<<'\n';

                }
            }
        }
        // cout<<"=========="<<'\n';
        step++;
    }
    return -1;
}

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>m>>k;;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            arr[i][j] = ch - '0';
            // cin>>arr[i][j];
        }
    }
    cout<<bfs(0, 0)<<'\n';
}