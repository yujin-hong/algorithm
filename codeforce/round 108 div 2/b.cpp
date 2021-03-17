#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int ans = 0;
        int arr[100001] = {0, };
        int num_len, divisible_num;
        cin>>num_len>>divisible_num;
        for(int j=0;j<num_len;j++) {
            int tmp;
            cin>>tmp;
            arr[tmp%divisible_num]++;
        }
        // for(int j=0;j<divisible_num;j++) {
        //     cout<<j<<' '<<arr[j]<<'\n';
        // }
        for(int j=1;j<=divisible_num/2;j++) {
            int diff = abs(arr[j]-arr[divisible_num-j]);
            if(arr[j]>0 && arr[divisible_num-j]>0 &&diff<2) {
                ans++;
            } else {
                ans=ans+diff;
            }
            // cout<<"ans:"<<ans<<'\n';
        }
        if(arr[0]>0) {
            ans++;
        }
        cout<<ans<<'\n';
    }
}