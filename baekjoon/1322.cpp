#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    vector<int> v;
    long long x, k;
    cin>>x>>k;
    long long tmp = 0;
    while((1<<tmp) <= x) {
        if((1<<tmp) < 0) break;
        if((x & (1<<tmp)) == 0) {
            v.push_back(tmp);
        }
        tmp++;
    }
    tmp = pow(2,tmp);
    long long ans = 0;
    int tmp2 = 0;
    while((1<<tmp2) <= k) {
        if((1<<tmp2) < 0) break;
        if((k & (1<<tmp2)) != 0) {
            if(tmp2<v.size()) {
                ans = ans + (1<<v[tmp2]);
            } else {
                ans = ans + tmp;
            }
        }
        if(tmp2 >= v.size()) {
            tmp = tmp * 2;
        }
        tmp2++;
    }
    cout<<ans<<'\n';
}