#include <iostream>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int a, b;
        cin>>a>>b;
        cout<<a*b<<'\n';
    }
}