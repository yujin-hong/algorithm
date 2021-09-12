#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, m;
    cin>>h>>m;
    if(h==0) {
        h = 23;
    } else {
        h = h-1;
    }

    m = m + 15;
    if(m >= 60) {
        m = m - 60;
        h = h + 1;
    }

    cout<<h%24<<' '<<m%60<<'\n';
}