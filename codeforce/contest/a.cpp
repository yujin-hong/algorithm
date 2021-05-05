#include <iostream>
#include <set>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        set<int> s;
        string ans = "YES";
        int str_len;
        cin>>str_len;
        char prev_ch = ' ';
        for(int i=0;i<str_len;i++) {
            char ch;
            cin>>ch;
            if(s.count(ch)==0) {
                s.insert(ch);
            } else {
                if(prev_ch != ch) {
                    ans = "NO";
                }
            }
            prev_ch = ch;
        }

        cout<<ans<<'\n';
    }
}