#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int arr[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int x, int y) {
    // cout<<"bfs: "<<x<<' '<<y<<'\n';
    int sum = 0;
    int visited[1001][1001];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while(!q.empty()) {
        auto [tx, ty] = q.front();
        // cout<<tx<<' '<<ty<<'\n';
        q.pop();
        sum++;
        for(int i=0;i<4;i++) {
            int px = tx+dx[i];
            int py = ty+dy[i];
            if(check_coord(px, py) && arr[px][py] == 0 && visited[px][py] == 0) {
                visited[px][py] = 1;
                q.push(make_pair(px, py));
            }
        }
    }
    return sum%10;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            arr[i][j] = ch - '0';
            // cout<<arr[i][j]<<' ';
        }
        // cout<<'\n';
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 1) {
                cout<<bfs(i, j);
            } else {
                cout<<0;
            }
        }
        cout<<'\n';
    }

}