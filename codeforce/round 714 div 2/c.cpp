#include <iostream>

using namespace std;

int mod_num = 1000000007;
long long pow_fun(int num);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        string num;
        int total_count;
        cin>>num>>total_count;
        long long ans = 0;
        for(int i=0;i<num.size();i++) {
            int tmp = num[i]-'0';
            int nine = (total_count-10+tmp)/9;
            long long first_order = 9*nine+10-tmp;
            long long last_order = first_order + nine;
            if(total_count<first_order) {
                ans = ans + 1;
            } else if(total_count >= first_order && total_count < last_order) {
                long long min_len = pow_fun(nine)+1;
                ans = ans + (min_len+(total_count-first_order)*nine);
            } else {
                ans = ans + pow_fun(nine+1);
            }
            ans = ans % mod_num;
            cout<<"ans: "<<ans<<'\n';
        }
        cout<<ans%mod_num<<'\n';
    }
}
long long pow_fun(int num) {
    int ret_val = 1;
    for(int i=0;i<num;i++) {
        ret_val = ret_val * 2;
    }
    return ret_val;
}