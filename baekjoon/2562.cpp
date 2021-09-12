#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int max = 0;
    int max_ind = -1;
    for(int i=0;i<9;i++) {
        int tmp;
        cin>>tmp;
        if(tmp > max) {
            max = tmp;
            max_ind = i;
        }
    }
    cout<<max<<'\n'<<max_ind+1<<'\n';
}