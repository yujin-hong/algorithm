#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long sum=0;
int ans = 0;
vector<long long> v; 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    int start = 0;
    for(int i=0;i<n;i++) {
        long long tmp;
        cin>>tmp;
        v.push_back(tmp);
        sum = sum + tmp;
        // cout<<sum<<'\n';
        if(sum==m) {
            ans++;
        }

        while(sum>=m) {
            if(start>v.size()-1) {
                break;
            }
            sum = sum-v[start];
            start++;
            if(sum==m) {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}