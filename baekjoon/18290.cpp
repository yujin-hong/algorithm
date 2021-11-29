#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int n, m, k;
int arr[11][11];
int ans=INT_MIN;
int denied_arr[11][11];

void update_denied_arr(int a, int b, int c) {
    if(a>=0 && b>=0 && a<n && b<m) {
        if(c==1) denied_arr[a][b]++;
        else denied_arr[a][b]--;
    }
}

pair<int, int> get_next_pair(int x, int y) {
    if(x==n-1 && y==m-1) return make_pair(-1, -1);
    if(y==m-1) {
        return make_pair(x+1, 0);
    }
    return make_pair(x, y+1);
}
void dfs(int count, int sum, int this_x, int this_y) {
    pair<int, int> next_pair = get_next_pair(this_x, this_y);
    if(count == k) {
        if(sum>ans) ans = sum;
        return;
    }
    if(next_pair == make_pair(-1, -1)) {
        return;
    }    

    int tx = next_pair.first;
    int ty = next_pair.second;

    if(denied_arr[tx][ty]==0) {
        update_denied_arr(tx, ty, 1);
        update_denied_arr(tx+1, ty, 1);
        update_denied_arr(tx-1, ty, 1);
        update_denied_arr(tx, ty+1, 1);
        update_denied_arr(tx, ty-1, 1);
        dfs(count + 1, sum + arr[tx][ty], tx, ty);
        update_denied_arr(tx, ty, -1);
        update_denied_arr(tx+1, ty, -1);
        update_denied_arr(tx-1, ty, -1);
        update_denied_arr(tx, ty+1, -1);
        update_denied_arr(tx, ty-1, -1);
        dfs(count, sum, tx, ty);
    } else {
        dfs(count, sum, tx, ty);
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    dfs(0, 0, 0, -1);
    cout<<ans<<'\n';
}