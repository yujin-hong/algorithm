#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    double rate = sqrt(a*a/(b*b+c*c));
    cout<< floor(rate*b) <<' '<<floor(rate*c)<<'\n';
}