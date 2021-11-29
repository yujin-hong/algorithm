#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dp[1001][3];
int v[1001][3];
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        for(int j=0;j<3;j++) {
            cin>>v[i][j];
        }
    }
    for(int i=0;i<3;i++) {
        dp[0][i] = v[0][i];
    }
    for(int i=1;i<tc_num;i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+v[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+v[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1])+v[i][2];
    }
    cout<<min(min(dp[tc_num-1][0], dp[tc_num-1][1]), dp[tc_num-1][2])<<'\n';
}