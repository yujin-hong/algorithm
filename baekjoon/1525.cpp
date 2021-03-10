#include <iostream>
#include <queue>
#include <map>
#include <tuple>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> dest;
queue<tuple<pair<int, int>, int>> q;
int step = 0;
map<tuple<pair<int, int>, int>, vector<vector<int>>> m;
bool check_range(int tx, int ty);

int main() {
    freopen("input.txt","r",stdin);
    pair<int, int> blank_pos = make_pair(2, 2);
    vector<vector<int>> start = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    m[make_tuple(blank_pos, 0)] = start;
    q.push(make_tuple(blank_pos, 0));

    for(int i=0;i<3;i++) {
        vector<int> tmp;
        for(int j=0;j<3;j++) {
            int t;
            cin>>t;
            tmp.push_back(t);
        }
        dest.push_back(tmp);
    }
    while(!q.empty()) {
        int qsize = q.size();
        int push_ind = 0;

        for(int i=0;i<qsize;i++) {
            int fx = get<0>(q.front()).first;
            int fy = get<0>(q.front()).second;
            int ind = get<1>(q.front());
            // cout<<fx<<' '<<fy<<'\n';
            q.pop();
            vector<vector<int>> plane = m[make_tuple(make_pair(fx, fy), ind)];
            // for(int i=0;i<3;i++) {
            //     for(int j=0;j<3;j++) {
            //         cout<<plane[i][j]<<' ';
            //     }
            //     cout<<'\n';
            // }
            if(plane == dest) {
                cout<<step<<'\n';
                return 0;
            };
            vector<vector<int>> test_plane = plane;
            for(int j=0;j<4;j++) {
                int tx = fx+dx[j];
                int ty = fy+dy[j];
                if(check_range(tx, ty)) {
                    swap(test_plane[fx][fy], test_plane[tx][ty]);
                    q.push(make_tuple(make_pair(tx, ty), push_ind));
                    m[make_tuple(make_pair(tx, ty), push_ind)] = test_plane;
                    test_plane = plane;
                    push_ind++;
                }                
            }
        }
        step++;
        // cout<<"================="<<step<<'\n';
        // if(step==4) break;
    }
    cout<<-1<<'\n';
    return 0;
}

bool check_range(int tx, int ty) {
    return tx>=0 && tx<3 && ty>=0 && ty<3;
}