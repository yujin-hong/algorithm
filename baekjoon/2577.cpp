#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> m;
    int a, b, c;
    cin>>a>>b>>c;
    long long multiple = a*b*c;
    string s= to_string(multiple);
    // cout<<s<<'\n';
    for(int i=0;i<s.size();i++) {
        m[s[i]-'0']++;
    }
    for(int i=0;i<=9;i++) {
        cout<<m[i]<<'\n';
    }
    // for(auto it = m.begin(); it != m.end(); it++){
	// 	cout << it->second << '\n';
	// }
}