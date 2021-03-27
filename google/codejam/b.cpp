#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int ans = 0;
        int n, m;
        string s;
        cin>>n>>m;
        cin>>s;
        char old_char = ' ';
        for(int j=0;j<s.size();j++) {
            char this_char = s[j];
            if(this_char == '?') continue;
            if(old_char == 'C' && this_char =='J') {
                ans = ans + n;
            } else if(old_char == 'J' && this_char == 'C') {
                ans = ans + m;
            }
            old_char = this_char;
        }
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
}