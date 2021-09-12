#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        cout<<tmp<<'\n';
        if(tmp>max_num) max_num = tmp;
        if(tmp<min_num) min_num = tmp; 
    }
    cout<<min_num<<' '<<max_num<<'\n';
}