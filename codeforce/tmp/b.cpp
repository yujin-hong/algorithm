#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int a, b, c;
        cin>>a>>b>>c;

        if(c == a-1 + a*(b-1)) {
            cout<<"YES"<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
        
    }
}