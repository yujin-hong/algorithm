#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        char ch;
        cin>>ch;
        int int_val = ch-'0';
        sum = sum + int_val;
    }
    cout<<sum<<'\n';
}