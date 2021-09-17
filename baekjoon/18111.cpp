#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[501][501];
int n, m, k;

int count_minus_block(int dest) {
    int ret = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]>dest) {
                ret = ret + (arr[i][j]-dest);
            }
        }
    }
    return ret;
}

int count_plus_block(int dest) {
    int ret = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]<dest) {
                ret = ret + (dest - arr[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    long long total_block_count = k;
    int min_time = INT_MAX;
    int ans_height = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            arr[i][j] = tmp;
            total_block_count=total_block_count+tmp;
        }
    }
    int avail_height = total_block_count/(n*m);
    for(int i=0;i<=avail_height;i++) {
        int minus_block = count_minus_block(i);
        int plus_block = count_plus_block(i);
        if(minus_block + k < plus_block) {
            break;
        }
        int time = minus_block*2+plus_block;
        if(time <= min_time) {
            min_time = time;
            ans_height = i;
        }
        // cout<<minus_block*2+plus_block<<'\n';
    }
    cout<<min_time<<' '<<ans_height<<'\n';
    
}