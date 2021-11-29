#include <bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FFOR(i,j,m,n) for(int i=0;i<m;i++) for(int j=0;j<n;j++)
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

#define pb push_back
typedef vector<int> vi;


int arr[21][21];
int n;
int min_val = INT_MAX;
vi start_team;
vi link_team;

void dfs(int ind, int start_score, int link_score) {
    if(ind == n) {
    // cout<<ind<<' '<<start_score<<' '<<link_score<<'\n';
        min_val = min(min_val, abs(start_score - link_score));
        return;
    }
    //put to start_team
    start_team.pb(ind);
    int sum = 0;
    for(int i: start_team) {
        sum += arr[ind][i] + arr[i][ind];
    }
    dfs(ind+1, start_score+sum, link_score);
    start_team.pop_back();

    //put to link_team
    link_team.pb(ind);
    sum = 0;
    for(int i: link_team) {
        sum += arr[ind][i] + arr[i][ind];
    }
    dfs(ind+1, start_score, link_score+sum);
    link_team.pop_back();

}

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n;
    FFOR(i, j, n, n) {
        cin>>arr[i][j];
    }
    dfs(0, 0, 0);
    cout<<min_val<<'\n';
}