#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, int> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> find_zero_position(vector<vector<int>> v);
bool check_range(int tx, int ty);
void print_plane(vector<vector<int>> fplane);
vector<vector<int>> convert_to_vector(string s);
string convert_to_string(vector<vector<int>> v);

int main() {
    vector<vector<int>> dest;
    freopen("input.txt","r",stdin);
    for(int i=0;i<3;i++) {
        vector<int> tmp;
        for(int j=0;j<3;j++) {
            int t;
            cin>>t;
            tmp.push_back(t);
        }
        dest.push_back(tmp);
    }
    int step = 0;
    vector<vector<int>> start = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    queue<string> q;
    string st = convert_to_string(start);
    q.push(st);
    visited[st] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            vector<vector<int>> fplane = convert_to_vector(q.front());
            // print_plane(fplane);
            if(fplane == dest) {
                cout<<step<<'\n';
                return 0;
            }
            q.pop();
            pair<int, int> zero_position = find_zero_position(fplane);
            int fx = zero_position.first;
            int fy = zero_position.second;
            // cout<<fx<<' '<<fy<<'\n';
            for(int j=0;j<4;j++) {
                vector<vector<int>> swap_plane = fplane;
                int tx = fx+dx[j];
                int ty = fy+dy[j];
                if(check_range(tx, ty)) {
                    swap(swap_plane[tx][ty], swap_plane[fx][fy]);
                    string sp = convert_to_string(swap_plane);
                    // print_plane(swap_plane);
                    // cout<<"visited: "<<visited[swap_plane]<<'\n';
                    if(visited[sp] != 1) {
                        visited[sp] = 1;
                        q.push(sp);
                    }
                }
            }
        }
        step++;
        // cout<<"================step "<<step<<'\n';
        // if(step==5) break;
    }
    cout<<-1<<'\n';
    return 0;
}

pair<int, int> find_zero_position(vector<vector<int>> v) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(v[i][j]==0) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(0, 0);
}

bool check_range(int tx, int ty) {
    return tx>=0 && tx<3 && ty>=0 && ty<3;
}

void print_plane(vector<vector<int>> fplane) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<fplane[i][j]<<' ';
        }
        cout<<'\n';
    }
}

string convert_to_string(vector<vector<int>> v) {
    string s = "";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            s=s+to_string(v[i][j]);
        }
    }
    return s;
}

vector<vector<int>> convert_to_vector(string s) {
    vector<vector<int>> v;
    int ind = 0;
    for(int i=0;i<3;i++) {
        vector<int> tmp;
        for(int j=0;j<3;j++) {
            tmp.push_back(s[ind++]-48);
            // cout<<tmp[j]<<'\n';
        }
        v.push_back(tmp);
    }
    return v;
}