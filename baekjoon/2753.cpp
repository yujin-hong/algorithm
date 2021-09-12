#include <iostream>
#include <bits/stdc++.h>

using namespace std;

set<int> s;
int main() {
    for(int i=0;i<10;i++) {
        int tmp;
        cin>>tmp;
        s.insert(tmp%42);
    }
    cout<<s.size()<<'\n';
}