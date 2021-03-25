#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int ans = 0;
        int str_len, k;
        cin>>str_len>>k;
        string s;
        cin>>s;
        int recent_star_ind = -1;
        int recent_x_pos = -1;
        for(int j=0;j<str_len;j++) {
            char ch = s[j];
            if(s[j]=='*') {
                if(recent_x_pos == -1) {
                    recent_x_pos = j;
                    ans++;
                } else if(j==recent_x_pos+k) {
                    recent_x_pos = j;
                    ans++;
                }
                recent_star_ind = j;
            } else {
                if(recent_x_pos!=recent_star_ind && j==recent_x_pos+k) {
                    recent_x_pos = recent_star_ind;
                    // cout<<j<<'\n';
                    ans++;
                }                
            }
        }
        if(recent_x_pos!=recent_star_ind) {
            ans++;
        }
        cout<<ans<<'\n';

    }
}    