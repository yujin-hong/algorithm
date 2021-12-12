#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int arr[51][51];
vector<pair<int, int>> cand;
vector<int> v;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = INT_MAX;
int n, t;

bool check_coord(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

bool check_full(int visited[51][51]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(visited[i][j]==0 & arr[i][j] ==0) {
                return false;
            }
        }
    }
    return true;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int num = 0;
    int empty_num = 0;
    int find_ans = 0;
    cin>>n>>t;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 2) {
                cand.push_back(make_pair(i,j));
                num++;
            } else if (arr[i][j] == 0) {
                empty_num++;
            }
        }
    }
    for(int i=0;i<num;i++) {
        if(i<t) v.push_back(0);
        else v.push_back(1);
    }
    do {
        int step = 0;
        int cnt = 0;
        // v.assign(n, 0);
        // v.assign(n, 1);
        // fill_n(arr, sizeof(arr), 0);
        int visited[51][51];
        memset(visited, 0, sizeof(visited));      
        queue<pair<int, int>> q;
        for(int i=0;i<num;i++) {
            if(v[i]==0) {
                auto [x, y] = cand[i];
                visited[x][y] = 1;
                q.push(cand[i]);
            }
        }
        while(!q.empty()) {
            int qsize = q.size();
            if(cnt == empty_num) {
                if(step<ans) ans = step;
                find_ans = 1;
                break;
            } 
            for(int i=0;i<qsize;i++) {
                auto [tx, ty] = q.front();
                q.pop();
                for(int j=0;j<4;j++) {
                    int px = tx+dx[j];
                    int py = ty+dy[j];
                    if(check_coord(px, py) && arr[px][py]!=1 && visited[px][py]==0) {
                        if(arr[px][py]==0) cnt++;
                        visited[px][py] = 1;
                        q.push(make_pair(px, py));
                    }
                }
            }
            step++;
        }   
        
    } while (next_permutation(v.begin(), v.end()));
    if(find_ans) {
        cout<<ans<<'\n';
    } else {
        cout<<-1<<'\n';
    }
}