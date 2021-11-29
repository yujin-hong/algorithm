#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int v[1001][3];
int dp[1001][3];

int get_min_val(int a, int b, int add) {
    if(a==0 && b==0) return 0;
    if(a==0) return b+add;
    if(b==0) return a+add;
    return min(a,b)+add;
}
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
    // Case 1: R-R
    dp[0][0] = v[0][0];
    for(int i=1;i<=tc_num;i++) {
        dp[i][0] = get_min_val(dp[i-1][1], dp[i-1][2],v[i][0]);
        dp[i][1] = get_min_val(dp[i-1][0], dp[i-1][2],v[i][1]);
        dp[i][2] = get_min_val(dp[i-1][0], dp[i-1][1],v[i][2]);
    }
    int cand_1 = dp[tc_num][0];
    // cout<<cand_1<<'\n';

    for(int i=0;i<3;i++) {
        dp[0][i] = 0;
    }

    // Case 2: G-G
    dp[0][1] = v[0][1];
    for(int i=1;i<=tc_num;i++) {
        dp[i][0] = get_min_val(dp[i-1][1], dp[i-1][2],v[i][0]);
        dp[i][1] = get_min_val(dp[i-1][0], dp[i-1][2],v[i][1]);
        dp[i][2] = get_min_val(dp[i-1][0], dp[i-1][1],v[i][2]);
    }
    int cand_2 = dp[tc_num][1];
    // cout<<cand_2<<'\n';

    for(int i=0;i<3;i++) {
        dp[0][i] = 0;
    }

    // Case 3: B-B
    dp[0][2] = v[0][2];
    for(int i=1;i<=tc_num;i++) {
        dp[i][0] = get_min_val(dp[i-1][1], dp[i-1][2],v[i][0]);
        dp[i][1] = get_min_val(dp[i-1][0], dp[i-1][2],v[i][1]);
        dp[i][2] = get_min_val(dp[i-1][0], dp[i-1][1],v[i][2]);
    }
    int cand_3 = dp[tc_num][2];
        // cout<<cand_3<<'\n';


    cout<<min(min(cand_1, cand_2), cand_3)<<'\n';

}