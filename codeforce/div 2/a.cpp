#include <numeric>
#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        long long num;
        long long ans = 0;
        cin>>num;
        while(1) {
            string s = to_string(num);
            int sum = 0;
            for(int j=0;j<s.size();j++) {
                sum = sum + (s[j]-'0');
            }
            // cout<<num<<' '<<sum<<'\n';
            for(int j=2;j<=sum;j++) {
                if(sum%j==0 && num%j==0) {
                    ans=num;
                    break;
                }
            }
            if(ans!=0) break;
            num++;
        }
        cout<<ans<<'\n';
    }
}