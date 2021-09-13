#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        vector<int> v;
        int num;
        cin>>num;
        for(int i=0;i<num;i++) {
            char ch;
            cin>>ch;
            if(ch== '*') {
                v.push_back(i);
            }        
        }
        if(v.size()==0) {
            cout<<0<<'\n';
            continue;
        }
        int mid_val = v[v.size()/2];
        long long ans = 0;
        for(int i=0;i<v.size();i++) {
            int this_ind = v[i];
            if(this_ind < mid_val) {
                ans = ans + (mid_val-this_ind);
            } else if (mid_val < this_ind) {
                ans = ans + (this_ind-mid_val);
            }
        }
        if(v.size()%2==0) {
            ans = ans - (v.size()/2)*(v.size()/2);
        } else {
            ans = ans - (v.size()/2) * (v.size()/2 + 1);
        }
        cout<<ans<<'\n';
    }
}
