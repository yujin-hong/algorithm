#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int dp[301];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    if(n==1) {
        cout<<v[0]<<'\n';
    } else if(n==2) {
        cout<<v[0]+v[1]<<'\n';
    } else if(n==3) {
        cout<<max(v[0]+v[2], v[1]+v[2])<<'\n';
    } else {
        dp[1] = v[0];
        dp[2] = v[0]+v[1];
        dp[3] = max(v[0]+v[2], v[1]+v[2]);
        for(int i=4;i<=n;i++) {
            dp[i] = max(dp[i-3]+v[i-2], dp[i-2])+v[i-1];
        }
        cout<<dp[n]<<'\n';
    }
}