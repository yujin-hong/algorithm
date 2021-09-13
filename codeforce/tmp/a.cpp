#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int a, b, c;
        cin>>a>>b>>c;
        if(a>b) {
            if((a-1)/b <= c) {
                cout<<"YES"<<'\n';
                continue;
            } else {
                cout<<"NO"<<'\n';
                            continue;
            }
        } else {
            if((b-1)/a <= c) {
                cout<<"YES"<<'\n';
                continue;
            } else {
                cout<<"NO"<<'\n';
                            continue;
            }        
        }
    }
}