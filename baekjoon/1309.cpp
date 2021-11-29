#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dp[100001][3];
int DIV_NUM = 9901;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int num;
    cin>>num;
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for(int i=1;i<num;i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%DIV_NUM;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%DIV_NUM;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%DIV_NUM;
    }
    int dest = num-1;
    cout<<(dp[dest][0] + dp[dest][1] + dp[dest][2])%DIV_NUM <<'\n';
}