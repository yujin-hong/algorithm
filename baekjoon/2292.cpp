#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin>>num;
    if(num==1) {cout<<1<<'\n'; return 0;}
    int res = (num-2)*2/6;
    int sqrt_val = sqrt(res);
    int ans;
    if(res < sqrt_val * (sqrt_val+1)) {
        ans = sqrt_val+1;
    } else {
        ans = sqrt_val+2;
    }
    cout<<ans<<'\n';
}