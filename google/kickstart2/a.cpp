#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int str_len;
        string str;
        cin>>str_len>>str;
        cout<<"Case #"<<k+1<<": ";
        int accum = 0;
        char before_char = 'A'-1;
        for(int i=0;i<str_len;i++) {
            if(str[i]>before_char) accum++;
            else accum = 1;
            before_char = str[i];
            cout<<accum<<' ';
        }
        cout<<'\n';
    }
}