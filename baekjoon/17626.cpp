#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[50001];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int num;
    cin>>num;
    dp[1] = 1;
    for(int i=2;i<=num;i++) {
        int min_num = INT_MAX;
        for(int j=1;j*j<=i;j++) {
            min_num = min(min_num, dp[i-j*j]+1);
        }
        dp[i] = min_num;
    }
    cout<<dp[num]<<'\n';
}