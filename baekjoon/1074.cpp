#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int ans = 0;

bool check_small_range(int sx, int sy, int size) {
    return r>=sx && r<sx+size && c>=sy && c<sy+size;
}
void check_range(int sx, int sy, int size) {
    if(size<1) return;
    if(check_small_range(sx, sy, size)) {
        check_range(sx, sy, size/2);
    } else if(check_small_range(sx, sy+size, size)) {
        ans = ans + size*size;
        check_range(sx, sy+size, size/2);
    } else if(check_small_range(sx+size, sy, size)) {
        ans = ans + size*size*2;
        check_range(sx+size, sy, size/2);
    } else {
        ans = ans + size*size*3;
        check_range(sx+size, sy+size, size/2);
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    cin>>n>>r>>c;
    check_range(0, 0, pow(2,n));
    cout<<ans<<'\n';
}