#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int str_len, dest;
        cin>>str_len>>dest;
        string sample_str;
        cin>>sample_str;
        int now_pair = 0;
        int ans;
        for(int j=0;j<str_len/2;j++) {
            if(sample_str[j]!=sample_str[str_len-j-1]) {
                now_pair++;
            } 
        }
        ans = abs(dest-now_pair);        
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
}