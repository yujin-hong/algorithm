#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    vector<int> v;
    long long sum = 0;
    int max = 0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        if(tmp>max) max = tmp;
        sum = sum + tmp;
    }
    cout<<(double)sum*100/(n*max)<<'\n';
}