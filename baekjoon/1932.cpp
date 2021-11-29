#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dp[501][501];
int v[501][501];
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int row_num;
    cin>>row_num;
    for(int i=0;i<row_num;i++) {
        for(int j=0;j<i+1;j++) {
            cin>>v[i][j];
        }
    }
    dp[0][0] = v[0][0];
    for(int i=1;i<row_num;i++) {
        dp[i][0] = dp[i-1][0] + v[i][0];
        for(int j=1;j<i;j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + v[i][j];
        }
        dp[i][i] = dp[i-1][i-1] + v[i][i];
    }
    // for(int i=0;i<row_num;i++) {
    //     for(int j=0;j<i+1;j++) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int dest = row_num-1;
    int ans = INT_MIN;
    for(int i=0;i<=dest;i++) {
        if(dp[dest][i]>ans) ans = dp[dest][i];
    }
    cout<<ans<<'\n';
}