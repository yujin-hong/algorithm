#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    int sum = 0;
    for(int i=0;i<5;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    for(int i=0;i<5;i++) {
        sum = sum + v[i] * v[i];
    }

    cout<<sum%10<<'\n';
}