#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int arr[201][201];
int fx, fy, tx, ty;
int n;
int find_ans = 0;
queue<pair<int, int>> q;
int ans = 0;

bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void bfs() {
    arr[fx][fy] = 1;
    q.push(make_pair(fx, fy));
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            pair<int, int> out = q.front();
            q.pop();
            int nx = out.first;
            int ny = out.second;
            if(nx == tx && ny == ty) {
                find_ans = 1;
                return;
            }
            for(int i=0;i<6;i++) {
                int nnx = nx + dx[i];
                int nny = ny + dy[i];
                if(check_coord(nnx, nny) && arr[nnx][nny]==0) {
                    arr[nnx][nny] = 1;
                    q.push(make_pair(nnx, nny));            
                }            
            }
        }
        ans++;
    }
}

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n;
    cin>>fx>>fy>>tx>>ty;
    bfs();
    if(find_ans) {
        cout<<ans<<'\n';
    } else {
        cout<<-1<<'\n';
    }
}