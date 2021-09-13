#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<long long> v;
    long long num = 1;
    while(true) {
        string s= to_string(num);
        if(s.find("666")!=string::npos) {
            v.push_back(num);
        }
        if(v.size()>10000) {
            break;
        }
        num++;
    }
    int tmp;
    cin>>tmp;
    cout<<v[tmp-1]<<'\n';
}