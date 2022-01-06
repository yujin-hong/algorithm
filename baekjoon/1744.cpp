#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<long long> v;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    } 
    sort(v.begin(), v.end());
    if(v.size()==1) {
        cout<<v[0]<<'\n';
        return 0;
    }
    long long ans1 = 0;
    int end_ind = -1;
    for(int i=0;i<v.size()-1;i+=2) {
        if(v[i]>=1) {
            end_ind = i;
            break;
        } else if(v[i+1]>=1) {
            ans1 = ans1 + v[i];
            end_ind = i+1;
            break;
        } else {
            end_ind = i+2;
            long long sum = v[i]*v[i+1];
            ans1 = ans1 + sum;
        }
    }
    // cout<<end_ind<<'\n';
    // cout<<ans1<<'\n';
    int end_ind2 = -1;
    long long ans2 = 0;
    for(int i=v.size()-1;i>=1;i-=2) {
        if(v[i]<=1) {
            end_ind2 = i;
            break;
        } else if(v[i-1]<=1) {
            end_ind2 = i-1;
            ans2 = ans2 + v[i];
            break;
        } else {
            end_ind2 = i-2;
            long long sum = v[i]*v[i-1];
            // cout<<v[i]<<' '<<v[i-1]<<' '<<sum<<'\n';
            ans2 = ans2 + sum;
        }
    }
    long long ans3=0;
    // cout<<end_ind<<' '<<end_ind2<<'\n';
    // if(end_ind2 >= end_ind) {
        for(int i=end_ind;i<=end_ind2;i++) {
            ans3 = ans3 + v[i];
        }
    // }
    // cout<<ans1<<'\n';
    // cout<<ans2<<'\n';
    // cout<<ans3<<'\n';
    cout<<ans1+ans2+ans3<<'\n';;
    // do {

    // }
}