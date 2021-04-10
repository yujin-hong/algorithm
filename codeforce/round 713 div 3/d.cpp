#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        vector<int> v;
        map<int, int> m;
        long long total = 0;
        int vec_len;
        cin>>vec_len;
        for(int i=0;i<vec_len+2;i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
            m[tmp]++;
            total = total+tmp;
        }
        sort(v.begin(), v.end());
        // for(int i=0;i<v.size();i++) {
        //     cout<<v[i]<<' ';
        // }
        int tmp1 = v[v.size()-1];
        // cout<<total<<'\n';
        if((total-tmp1*2!=tmp1 && m[total-tmp1*2]>0) || (total-tmp1*2==tmp1 && m[total-tmp1*2]>1)) {
            int count_tmp1 = 1;
            int count_remain1 = 1;
            for(int i=0;i<vec_len+2;i++) {
                if(count_tmp1==1 && v[i]==tmp1) {
                    count_tmp1 = 0;
                    continue;
                }
                if(count_remain1==1 && v[i]==total-tmp1*2) {
                    count_remain1 = 0;
                    continue;
                }
                cout<<v[i]<<' ';
            }
            cout<<'\n';
            continue;
        }
        int tmp2 = v[v.size()-2];
        if((total-tmp2*2!=tmp2 && m[total-tmp2*2]>0) || (total-tmp2*2==tmp2 && m[total-tmp2*2]>1)) {
            int count_tmp2 = 1;
            int count_remain2 = 1;            
            for(int i=0;i<vec_len+2;i++) {
                if(count_tmp2==1 && v[i]==tmp2) {
                    count_tmp2 = 0;
                    continue;
                }
                if(count_remain2==1 && v[i]==total-tmp2*2) {
                    count_remain2 = 0;
                    continue;
                }
                cout<<v[i]<<' ';
            }
            cout<<'\n';
            continue;
        }
        cout<<-1<<'\n';        
    }
}