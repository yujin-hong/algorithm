#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt","r",stdin);
    int a, b, v;
    cin>>a>>b>>v;
    if((v-b)%(a-b) == 0) {
        cout<<(v-b)/(a-b)<<'\n';
    } else {
        cout<<(v-b)/(a-b)+1<<'\n';
    }
    // cout<<ceil((double)(v-b)/(a-b))<<'\n';
}
