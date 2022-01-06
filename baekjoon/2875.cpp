#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> v;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int n, m, k;
    cin>>n>>m>>k;
    // cout<<n<<' '<<m<<' '<<k<<'\n';
    int now_team = min(n/2, m);
    if(k <= (n + m - now_team*3)) {
        cout<<now_team<<'\n';
    } else {
        int remain = k - (n + m - now_team*3);
        cout<<now_team - (remain +2)/3<<'\n';
    }
}