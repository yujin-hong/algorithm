#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    string s;
    std::getline(cin, s);

    for(int i=0;i<num;i++) {
        int ans = 0;
        int accum = 0;
        std::getline(cin, s);
        // cout<<s<<'\n';
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'O') {
                accum++;
                // cout<<accum<<'\n';
                ans = ans + accum;
            } else {
                accum = 0;
            }
        }
        cout<<ans<<'\n';
    }
}