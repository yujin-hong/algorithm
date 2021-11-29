#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v[1001];
int main() {
    freopen("input.txt","r",stdin);
    int num, tc_num;
    cin>>num>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b, c));

    }
}