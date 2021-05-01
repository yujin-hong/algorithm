#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int ans = 1;
        vector<int> ans_vec;
        vector<int> v;
        int str_len;
        cin>>str_len;
        cout<<"str_len: "<<str_len<<'\n';
        for(int i=0;i<str_len;i++) {
            int ch; 
            cin>>ch;
            v.push_back(ch);
        }
        cout<<"print v: ";
        for(int i=0;i<str_len;i++) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        int old_ind = 0;
        int new_ind = 0;
        int prev_diff = v[1]-v[0];
        for(int i=2;i<str_len;i++) {
            int now_diff = v[i]-v[i-1];
            cout<<prev_diff<<' '<<now_diff<<'\n';
            if(now_diff == prev_diff) {
                ans_vec.push_back(i-old_ind);
                continue;
            } else {
                cout<<"yey i: "<<i<<'\n';
                cout<<new_ind<<' '<<old_ind<<'\n';
                ans_vec.push_back(i-old_ind);
                old_ind = new_ind;
                new_ind = i-1;
                v[i] = v[i-1]+prev_diff;
                prev_diff = now_diff;
            }
        }
        for(int i=0;i<ans_vec.size();i++) {
            cout<<ans_vec[i]<<' ';
        }
        cout<<'\n';
        cout<<"Case #"<<k+1<<": "<<ans<<'\n';
    }
}