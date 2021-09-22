#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num, tc_num;
    cin>>num>>tc_num;
    for(int i=1;i<=num;i++) {
        for(int j=1;j<=num;j++) {
            cin>>arr[i][j];
        }
    }
    sum[1][1] = arr[1][1];
    int sum1 = sum[1][1];
    int sum2 = sum[1][1];
    for(int i=2;i<=num;i++) {
        sum1 = sum1 + arr[1][i];
        sum[1][i] = sum1;
        sum2 = sum2 + arr[i][1];
        sum[i][1] = sum2;
    }
    for(int i=2;i<=num;i++) {
        for(int j=2;j<=num;j++) {
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    for(int i=0;i<tc_num;i++) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        // cout<<sum[x2][y2]<<'\n';
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<'\n';
    }
}