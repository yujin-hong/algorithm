#include <iostream>

using namespace std;

int dp[101];

int main() {
    int num;
    cin>>num;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=100;i++) {
        dp[i] = dp[i-1]+1;
        for(int j=3;j<i;j++) {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
        if(i==num) break;
    }
    cout<<dp[num]<<'\n';
}