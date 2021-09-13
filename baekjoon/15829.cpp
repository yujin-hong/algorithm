#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int num;
    long long sum = 0;
    long long M = 1234567891;
    long long multi_num = 31;
    long long accum = 1;
    cin>>num;
    for(int i=0;i<num;i++) {
        char ch;
        cin>>ch;
        long long this_num = ch-'a'+1;
        sum = (sum + (this_num * accum)%M)%M;
        accum = accum * multi_num % M;
    }
    cout<<sum<<'\n';
}