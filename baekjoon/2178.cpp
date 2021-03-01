#include <iostream>
#include <queue>

using namespace std;

int arr[101][101] = {0,};
int visited[101][101] = {0,};
int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int n, m;
int ans = 1;

int bfs(int sx, int sy);
bool validate_size(int tx, int ty);

int main() {
    //bfs
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin>>c;
            arr[i][j] = c-48;
        }
    }
    cout<<bfs(0, 0)<<'\n';
}

int bfs(int sx, int sy) {
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            pair<int, int> front = q.front();
            int fx = front.first;
            int fy = front.second;
            if(fx==n-1 && fy==m-1) {
                return ans;
            }
            q.pop();
            for(int i=0;i<4;i++) {
                int tx = fx+cx[i];
                int ty = fy+cy[i];
                if(validate_size(tx, ty) && arr[tx][ty]==1 && visited[tx][ty]==0) {
                    q.push(make_pair(tx, ty));
                    visited[tx][ty]=1;
                }
            }
        }
        ans++;
    }
    return ans;
}

bool validate_size(int tx, int ty) {
    return tx>=0 && tx<n && ty>=0 && ty<m;
}