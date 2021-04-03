#include <iostream>

using namespace std;
string parse_string(string str, int st, int end);
bool check_string_unpalindrom(string str);
bool check_string_unpalindrom_possible(string str);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        string s;
        cin>>s;
        if(check_string_unpalindrom_possible(s)) {
            cout<<"YES"<<'\n';
            string first_inserted_string = "a"+s;
            if(check_string_unpalindrom(first_inserted_string)) {
                cout<<first_inserted_string<<'\n';
            } else {
                string last_inserted_string = s+"a";
                cout<<last_inserted_string<<'\n';
            }            
        } else {
            cout<<"NO"<<'\n';
        }
    }
}

bool check_string_unpalindrom_possible(string str) {
    for(int i=0;i<str.size();i++) {
        if(str[i]!='a') return true;
    }
    return false;
}

bool check_string_unpalindrom(string str) {
    for(int i=0;i<str.size()/2;i++) {
        if(str[i]!=str[str.size()-i-1]) {
            return true;
        }
    }
    return false;
}