#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        m[tmp]++;
    }
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int tmp;
        cin>>tmp;
        cout<<m[tmp]<<' ';
    }
    cout<<'\n';
}