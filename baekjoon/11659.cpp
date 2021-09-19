#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int arr[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num_count, tc_num;
    cin>>num_count>>tc_num;
    for(int i=0;i<num_count;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    arr[1] = v[0];
    for(int i=2;i<=v.size();i++) {
        arr[i] = arr[i-1]+v[i-1];
    }
    for(int i=0;i<tc_num;i++) {
        int n,m;
        cin>>n>>m;
        cout<<arr[m]-arr[n-1]<<'\n';
    }
}