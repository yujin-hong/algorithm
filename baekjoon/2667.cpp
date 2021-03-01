#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num;
int arr[26][26];
int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, 1, 0, -1};
int step;
vector<int> ans;

int dfs(int sx, int sy);
bool check_range(int tx, int ty);

int main() {
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            char c;
            cin>>c;
            arr[i][j] = c-48;
        }
    }
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            if(arr[i][j]==1) {
                step = 0;
                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<'\n';
    }
}

int dfs(int sx, int sy) {
    // cout<<sx<<' '<<sy<<'\n';
    step++;
    arr[sx][sy]=0;
    for(int i=0;i<4;i++) {
        int tx = sx+cx[i];
        int ty = sy+cy[i];
        if(check_range(tx, ty) && arr[tx][ty]==1) {
            dfs(tx, ty);
        }
    }
    return step;
}


bool check_range(int tx, int ty) {
    return tx>=0 && tx<num && ty>=0 && ty<num;
}


