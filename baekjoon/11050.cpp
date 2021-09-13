#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    if(k==0) {
        cout<<"1"<<'\n';
    } else {
        int nfac = 1;
        for(int i=1;i<=n;i++) {
            nfac = nfac * i;
        }
        int kfac = 1;
        for(int i=1;i<=k;i++) {
            kfac = kfac * i;
        }
        int nkfac = 1;
        for(int i=1;i<=n-k;i++) {
            nkfac = nkfac * i;
        }
        cout<<nfac/(kfac * nkfac)<<'\n';
    }
}
