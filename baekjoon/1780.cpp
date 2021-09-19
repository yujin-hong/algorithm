#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[3000][3000];
int ans[3];

bool check_all_same(int sx, int sy, int size) {
    int val = arr[sx][sy];
    for(int i=sx;i<sx+size;i++) {
        for(int j=sy;j<sy+size;j++) {
            if(arr[i][j]!=val) {
                return false;
            }
        }
    }
    return true;
}
void check_count(int sx, int sy, int size) {
    if(check_all_same(sx, sy, size)) {
        ans[arr[sx][sy]] = ans[arr[sx][sy]] + 1;
        return;
    } else {
        int now_size = size/2;
        for(int i=sx;i<sx+size;i=i+now_size) {
            for(int j=sy;j<sy+size;j=j+now_size) {
                check_count(i,j,now_size);
            }
        }
    }

}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            cin>>arr[i][j];
        }
    }
    check_count(0, 0, num);
    cout<<ans[0]<<'\n'<<ans[1]<<'\n';
}