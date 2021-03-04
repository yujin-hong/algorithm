#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int dp[1000001];

int main() {
    // freopen("input.txt","r",stdin);
    int m;
    cin>>m;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=m;i++) {
        vector<int> v;
        int val = INT_MAX;
        if(i%3 == 0) {
            v.push_back(dp[i/3]);
        }
        if(i%2 == 0) {
            v.push_back(dp[i/2]);
        }
        v.push_back(dp[i-1]);
        for(int j=0;j<v.size();j++) {
            val = min(val, v[j]);
        }
        dp[i] = val+1;
    }
    cout<<dp[m]<<'\n';
}