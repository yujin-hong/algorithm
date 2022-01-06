#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> v;

int m, n;
int ans;
int get_split(int num) {
    // cout<<"num: "<<num<<'\n';
    int tans = 0;
    int sum = 0;
    for(int ind=0;ind<m;ind++) {
        // cout<<v[ind]<<' ';
        if(v[ind]>num) {
            return n+1;
        }
        sum+=v[ind];
        if(sum > num) {
            // cout<<"========"<<'\n';
            tans++;
            sum = 0;
            ind--;
        }
    }
    return tans + 1;
}
void bin_search(int left, int right) {
    while(left<=right) {
        int mid = (left+right)/2;
        int res = get_split(mid);
        if(res < n) {
            ans = mid;
            right = mid - 1;
        } else if(res > n) {
            left = mid + 1;
        } else {
            // cout<<"hi"<<'\n';
            ans = mid;
            right = mid - 1;
        }
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>m>>n;
    // cout<<m<<' '<<n<<'\n';
    int sum = 0;
    for(int i=0;i<m;i++) {
        int t;
        cin>>t;
        sum+=t;
        v.push_back(t);
    }
    // cout<<get_split(17)<<'\n';

    bin_search(0, sum);
    cout<<ans<<'\n';
}