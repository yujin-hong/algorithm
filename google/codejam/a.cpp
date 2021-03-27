#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        vector<int> v;
        int len;
        cin>>len;
        int ans = 0;
        for(int j=0;j<len;j++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int j=0;j<len-1;j++) {
            // cout<<"-==========="<<'\n';
            // for(int k=0;k<v.size();k++) {
            //     cout<<v[k]<<' ';
            // }
            // cout<<'\n';
            // cout<<"+=========="<<'\n';
            int now_num = v[j];
            int min_ind = -1;
            int min_val = INT_MAX;
            //find minimum ind
            for(int k=j;k<len;k++) {
                if(v[k]<min_val) {
                    min_ind = k;
                    min_val = v[k];
                }
            }
            vector<int> tmp;
            for(int k=0;k<j;k++) {
                tmp.push_back(v[k]);
            }
            for(int k=min_ind;k>=j;k--) {
                tmp.push_back(v[k]);
            }
            for(int k=min_ind+1;k<len;k++) {
                tmp.push_back(v[k]);
            }
            v = tmp;
            // cout<<j<<' '<<min_ind<<'\n';
            ans = ans + (min_ind - j +1 );
        }
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
}