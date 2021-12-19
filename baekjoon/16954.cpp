#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
char arr[8][8];
int ans = 0;

bool check_coord(int x, int y) {
    return x>=0 && x<8 && y>=0 && y<8;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        // cout<<"qsize: "<<qsize<<'\n';
        if(step > 8) {
            ans = 1;
            break;
        }
            // if(step == 3) break;

        for(int i=0;i<qsize;i++) {
            auto [tx, ty] = q.front(); q.pop();
            // cout<<tx<<' '<<ty<<'\n';
            if(tx == 0 && ty == 7) {
                ans = 1;
                break;
            }
            int visited[8][8] = {0,};
            for(int j=0;j<9;j++) {
                int px = tx+dx[j];
                int py = ty+dy[j];
                if(check_coord(px, py) && visited[px][py] == 0) {
                    // cout<<px<<' '<<py<<' '<<step<<' '<<arr[px][py]<<' '<<arr[px-step][py]<<'\n';
                    if(px-step >= 0) { // 8단계 이하라서 벽이 남아있을 경우
                        if(arr[px-step][py] == '.') {
                            if(px-step-1>=0) {
                                if(arr[px-step-1][py] == '.') {
                                    visited[px][py] = 1;
                                    q.push(make_pair(px, py));
                                }
                            } else {
                                visited[px][py] = 1;
                                q.push(make_pair(px, py));
                            }
                        } 
                    } else { // 8단계가 지나서 벽이 없을경우
                        visited[px][py] = 1;
                        q.push(make_pair(px, py));
                    }
                }
            }

        }
        // cout<<"=========="<<'\n';
        step++;
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cin>>arr[i][j];
        }
    }
    //     for(int i=0;i<8;i++) {
    //     for(int j=0;j<8;j++) {
    //         cout<<arr[i][j];
    //     }
    //     cout<<'\n';
    // }
    bfs(7, 0);
    cout<<ans<<'\n';
}