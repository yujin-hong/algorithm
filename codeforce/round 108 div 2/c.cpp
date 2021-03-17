#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int n,k;
        cin>>n>>k;
        if(n%2==0) {
            if(n%4==0) {
                cout<<n/4<<' '<<n/4<<' '<<n/2<<'\n';
            } else {
                cout<<n/2-1<<' '<<n/2-1<<' '<<2<<'\n';
            }
        } else {
            cout<<(n-1)/2<<' '<<(n-1)/2<<' '<<1<<'\n';
        }
    }
}