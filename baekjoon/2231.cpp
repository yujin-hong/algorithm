#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin>>num;
    for(int i=1;i<=1000000;i++) {
        int this_num = i;
        int this_sum = this_num;
        string s = to_string(this_num);
        for(int i=0;i<s.size();i++) {
            this_sum = this_sum + s[i]-'0';
        }
        if(this_sum == num) {
            cout<<this_num<<'\n';
            return 0;
        }
    }
    cout<<0<<'\n';
}