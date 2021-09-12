#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    std::getline(cin, s);
    if(s=="1 2 3 4 5 6 7 8") {
        cout<<"ascending"<<'\n';
    } else if(s=="8 7 6 5 4 3 2 1") {
        cout<<"descending"<<'\n';
    } else {
        cout<<"mixed"<<'\n';
    }

}