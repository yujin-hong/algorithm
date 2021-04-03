#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int num[2] = {0,};
        int str_len;
        cin>>str_len;
        string a, b;
        cin>>a;
        cin>>b;
        int prev_status = -1;
        int fl = 1;
        for(int j=0;j<=str_len;j++) {
            int status = -1;
            if(j==str_len || a[j]==b[j]) {
                status = 1;
            } else {
                status = 0;
            }
            if(status!=prev_status) {
                //check whether count num is same
                // cout<<j<<' '<<num[0]<<' '<<num[1]<<'\n';
                if(num[0]!=num[1]) {
                    fl = -1;
                    break;
                }
            }
            num[a[j]-'0']++;
            prev_status = status;
        }
        if(fl==-1) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}