#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long dp[101];

void calc_dp() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    for(int i=7;i<=100;i++) {
        dp[i] = dp[i-1]+dp[i-5];
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    calc_dp();
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int t;
        cin>>t;
        cout<<dp[t]<<'\n';
    }
}