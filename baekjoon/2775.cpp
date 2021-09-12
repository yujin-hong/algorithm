#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[15][15];
int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    arr[0][0] = 1;
    for(int i=1;i<=14;i++) {
        arr[i][1] = 1;
        arr[0][i] = i;
    }
    for(int i=1;i<=14;i++) {
        for(int j=2;j<=14;j++) {
            arr[i][j] = arr[i][j-1]+arr[i-1][j];
        }
    }
    for(int i=0;i<tc_num;i++) {
        int m, n;
        cin>>m>>n;
        cout<<arr[m][n]<<'\n';
    }
}