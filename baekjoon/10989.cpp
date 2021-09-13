#include <iostream>
#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        m[tmp]++;
    }
    for(int i=1;i<=10000;i++) {
        for(int j=0;j<m[i];j++) {
            cout<<i<<'\n';
        }
    }
}