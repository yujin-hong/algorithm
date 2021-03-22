#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        // cout<<"==========="<<'\n';
        vector<int> v;
        int sample_len;
        cin>>sample_len;
        for(int j=0;j<sample_len;j++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        if(sample_len<3) {
            cout<<0<<'\n';
            continue;
        }
        long long old_sample_val = 0;
        int fl = 0;
        for(int j=1;j<sample_len-1;j++) {
            long long sample_val = abs(v[j-1]-2*v[j]+v[j+1]);
            if(sample_val!=0) {
                if(sample_val>v[j-1] && sample_val>v[j] && sample_val>v[j+1]) {
                    if(old_sample_val==0) {
                        old_sample_val = sample_val;
                    } else if(sample_val!=old_sample_val) {
                        fl = 1;
                        break;
                    }
                } else {
                    fl=1;
                    break;
                }
            }
        }
        if(fl==1) {
            cout<<-1<<'\n';
            continue;
        }
        if(old_sample_val==0) {
            cout<<0<<'\n';
        } else {
            cout<<old_sample_val<<' ';
            cout<<(v[1]-v[0]+old_sample_val)%old_sample_val<<'\n';            
            
        }

    }
}