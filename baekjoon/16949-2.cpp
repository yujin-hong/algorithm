#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int arr[1001][1001];
int group[1001][1001];
vector<int> group_size;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[1001][1001];

int n, m;

bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(int x, int y) {
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while(!q.empty()) {
        auto [tx, ty] = q.front();
        v.push_back(make_pair(tx, ty));
        q.pop();
        for(int i=0;i<4;i++) {
            int px = tx+dx[i];
            int py = ty+dy[i];
            if(check_coord(px, py) && arr[px][py] == 0 && visited[px][py] == 0) {
                visited[px][py] = 1;
                q.push(make_pair(px, py));
            }
        }
    }
    group_size.push_back(v.size()%10);
    for(int i=0;i<v.size();i++) {
        auto [tx, ty] = v[i];
        group[tx][ty] = group_size.size();
    }
}

int get_num(int x, int y) {
    int ans = 0;
    set<int> s;
    for(int i=0;i<4;i++) {
        int tx = x + dx[i];
        int ty = y+dy[i];
        if(check_coord(tx, ty)) {
            if(group[tx][ty]!=0) s.insert(group[tx][ty]);
        }
    }
    for(int group_no : s) {
        ans+=group_size[group_no-1];
    }
    return ans+1;
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
        }
    }


    //calculate group
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0 && group[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                cout<<0;
            } else {
                cout<<get_num(i, j)%10;
            }
        }
        cout<<'\n';
    }

}