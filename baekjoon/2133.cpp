#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int dp[31];
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int n;
    cin>>n;
    dp[2] = 3;
    if(n%2==0) {
        for(int i=4;i<=n;i=i+2) {
            for(int j=2;j<i;j=j+2) {
                int unique_count = 0;
                if(j==2) unique_count = 3;
                else unique_count = 2;
                dp[i] = dp[i]+unique_count*dp[i-j];
            }
            dp[i] = dp[i] + 2;
        }
        cout<<dp[n]<<'\n';
    } else {
        cout<<0<<'\n';
    }
}