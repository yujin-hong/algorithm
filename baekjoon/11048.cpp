#include <iostream>

using namespace std;

int arr[1001][1001];
int ans[1001][1001];
int main() {
    freopen("input.txt", "r",stdin);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    ans[0][0] = arr[0][0];
    for(int i=1;i<m;i++) {
        ans[0][i] = ans[0][i-1]+arr[0][i];
    }
    for(int i=1;i<n;i++) {
        ans[i][0] = ans[i-1][0]+arr[i][0];
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            ans[i][j] = max(ans[i-1][j], ans[i][j-1])+arr[i][j];
        }
    }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout<<ans[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans[n-1][m-1]<<'\n';
}