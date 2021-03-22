#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

set<int> broken_buttons;
vector<int> valid_buttons;

int check(int size, int dest);

int main() {
    freopen("input.txt","r",stdin);
    int dest;
    cin>>dest;
    string str_dest = to_string(dest);
    int str_len = str_dest.size();
    int arr_len;
    cin>>arr_len;
    for(int i=0;i<arr_len;i++) {
        int tmp;
        cin>>tmp;
        broken_buttons.insert(tmp);
    }
    // for(int i=0;i<9;i++) {
    //     if(broken_buttons.count(i)==0) {
    //         for(int j=0;j<str_len+1;j++) {
    //             valid_buttons.push_back(i);
    //         }
    //     }
    // }
    int min_val = abs(dest-100);
    for(int i=0;i<=599999;i++) {
        int fl = 0;
        string s = to_string(i);
        for(int j=0;j<s.size();j++) {
            if(broken_buttons.count(s[j]-'0')!=0) {
                fl=1;
                break;
            }
        }
        if(fl==1) continue;
        int tmp_min_val = abs(dest-i) + s.size();
        // cout<<"i: "<<i<<"val: "<<abs(dest-i)<<'\n';
        if(tmp_min_val<min_val) min_val = tmp_min_val;
    }
    cout<<min_val<<'\n';

}
