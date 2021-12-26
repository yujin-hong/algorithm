#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> a;
vector<int> b;
vector<int> c;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<m;i++) {
        int tmp;
        cin>>tmp;
        b.push_back(tmp);
    }

    int s1 = 0;
    int s2 = 0;

    while(s1 < n && s2 < m) {
        if(a[s1] < b[s2]) {
            c.push_back(a[s1++]);
        } else {
            c.push_back(b[s2++]);
        }
    }
    while(s1 < n) {
        c.push_back(a[s1++]);
    }
    while(s2 < m) {
        c.push_back(b[s2++]);
    }

    for(int i=0;i<n+m;i++) {
        cout<<c[i]<<' ';
    }
    cout<<'\n';
}