#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> v;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    long long width, height;
    cin>>height>>width;
    if(height == 1) {
        cout<<1<<'\n';
    } else if(height == 2) {
        if(width<7) {
            cout<<(width+1)/2<<'\n';
        } else {
            cout<<4<<'\n';
        }
    } else {
        if(width<=4) cout<<width<<'\n';
        else if(width ==5) cout<<4<<'\n';
        else cout<<width-2<<'\n';
    }
}