#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> num;
vector<char> oper;
vector<int> minus_num;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    string s;
    string this_num;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        char ch = s[i];
        if(ch>='0' && ch<='9') {
            this_num+=ch;
        } else {
            num.push_back(stoi(this_num));
            oper.push_back(ch);
            this_num="";
        }
    }
    num.push_back(stoi(this_num));
    // for(int i=0;i<num.size();i++) {
    //     cout<<num[i]<<' ';
    // }
    long long add_num = num[0];
    for(int i=0;i<oper.size();i++) {
        if(oper[i]=='+') {
            add_num = add_num + num[i+1];
        } else {
            minus_num.push_back(add_num);
            add_num = num[i+1];
        }
    }
    minus_num.push_back(add_num);
    int ans = minus_num[0];
    // cout<<ans<<' '<<minus_num[1]<<'\n';
    for(int i=1;i<minus_num.size();i++) {
        ans = ans - minus_num[i];
    }
    cout<<ans<<'\n';
}