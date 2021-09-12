#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, num;
    cin>>m>>num;
    for(int i=0;i<m;i++) {
        int tmp;
        cin>>tmp;
        if(tmp<num) cout<<tmp<<' ';
    }

}