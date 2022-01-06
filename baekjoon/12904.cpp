#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    string s, t;
    cin>>s>>t;
    while(s.length()<t.length()) {
        if(t.back() == 'A') {
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if(s == t) {
        cout<<1<<'\n';
    } else {
        cout<<0<<'\n';
    }
}