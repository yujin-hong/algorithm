#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int x, y, z;
        cin>>x>>y>>z;
        int height = (z-1)%x+1;
        int width = (z-1)/x+1;
        if(width<10) {
            cout<<height<<"0"<<width<<'\n';
        } else {
            cout<<height<<width<<'\n';
        }
        
    }

}