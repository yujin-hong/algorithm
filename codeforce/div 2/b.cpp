#include <iostream>
#include <climits>

using namespace std;

int log_2(int n);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int arr[21] = {0,};
        int max_num = INT_MIN;
        int num, dest;
        cin>>num>>dest;
        for(int i=0;i<num;i++) {
            int tmp;
            cin>>tmp;
            arr[log_2(tmp)]++;
            if(log_2(tmp)>max_num) max_num = log_2(tmp);
        }
        cout<<max_num<<'\n';
        for(int i=0;i<max_num;i++) {
            cout<<arr[i]<<' ';
        }
    }
    
}

int log_2(int n) {
    int ans = 0;
    while(n!=1) {
        n=n/2;
        ans++;
    }
    return ans;
}