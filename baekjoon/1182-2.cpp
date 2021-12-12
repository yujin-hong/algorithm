#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int arr[21];
int ans = 0;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int num, dest;
    cin>>num>>dest;
    for(int i=0;i<num;i++) {
        cin>>arr[i];
    }
    int all_set_num = (1<<num) - 1;
    for(int i=1;i<all_set_num;i++) {
        int sum = 0;
        for(int j=0;j<num;j++) {
            if(i & (1<<j)) {
                sum+=arr[j];
            }
        }
        if(sum==dest) {
            ans++;
        }
    }
    cout<<ans<<'\n';
}