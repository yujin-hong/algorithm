#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        long long a, b, c;
        cin>>a>>b>>c;
        long long tmp1 = (c-1)/a;
        long long tmp2 = c%a;
        if(tmp2==0) tmp2 = a;
        long long ans = (tmp2-1)*b+tmp1+1;
        cout<<ans<<'\n';
    }
}