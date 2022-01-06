#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> v;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int n, k;
    cin>>n>>k;

    for(int i=1;i<=(n/2);i++) {
        int m = n-i;
        int mul = i * m;
        if(k <= mul) {
            int a = k / m;
            int b = k % m;
            // cout<<a<<' '<<b<<'\n';
            for(int j=0;j<n;j++) {
                if(j<a) {
                    cout<<'A';
                } else if(b!=0 && j == (n - b-1)) {
                    cout<<'A';
                } else {
                    cout<<'B';
                }
            }
            return 0;
        }
    }
    cout<<-1<<'\n';
    return 0;
}