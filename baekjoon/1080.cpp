#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int start[51][51];
int dest[51][51];
int ans = 0;
int n, m;
int check_same() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(start[i][j] != dest[i][j]) {
                return -1;
            }
        }
    }
    return ans;
}

void flip(int x, int y) {
    for(int i=x;i<x+3;i++) {
        for(int j=y;j<y+3;j++) {
            start[i][j] = 1-start[i][j];
        }
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            start[i][j] = ch - '0';
            // cin>>start[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            dest[i][j] = ch - '0';
        }
    }
    if(n<3 || m<3) {
        cout<<check_same()<<'\n';
        return 0; 
    }
    for(int i=0;i<n-2;i++) {
        for(int j=0;j<m-2;j++) {
            if(start[i][j] != dest[i][j]) {
                ans++;
                flip(i, j);
            }
        }
    }
    cout<<check_same()<<'\n';
}