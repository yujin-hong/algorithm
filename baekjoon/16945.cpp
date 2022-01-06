#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
int arr[4][4];
vector<int> v;
int ans = INT_MAX;

bool check_magic() {
    return (v[0]+v[1]+v[2] == 15) && (v[3]+v[4]+v[5] == 15) && (v[6]+v[7]+v[8] == 15) 
    && (v[0]+v[3]+v[6] == 15) && (v[1]+v[4]+v[7] == 15) && (v[2]+v[5]+v[8] == 15)
    && (v[0]+v[4]+v[8] == 15) && (v[2]+v[4]+v[6] == 15);
}

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=9;i++) {
        v.push_back(i);
    }
    do {
        if(!check_magic()) {
            continue;
        }
        int this_ans = 0;
        int v_ind = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int diff = abs(arr[i][j] - v[v_ind++]);
                this_ans += diff;
            }
        }
        if(this_ans < ans) ans = this_ans;
    } while (next_permutation(v.begin(), v.end()));
    cout<<ans<<'\n';
}