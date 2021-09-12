#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    while(true) {
        vector<int> v;
        int a, b, c;
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0) {
            break;
        }
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        if(v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) {
            cout<<"right"<<'\n';
        } else {
            cout<<"wrong"<<'\n';
        }
    }
}