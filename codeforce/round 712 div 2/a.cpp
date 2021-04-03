#include <iostream>

using namespace std;
string parse_string(string str, int st, int end);
bool check_string_unpalindrom(string str);
string check_string_unpalindrom_possible(string str);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        string s;
        cin>>s;
        //create inserted string
        string res = check_string_unpalindrom_possible(s);
        if(res!="") {
            cout<<"YES"<<'\n';
            cout<<res<<'\n';
        } else {
            cout<<"NO"<<'\n';
        };
    }
}

string check_string_unpalindrom_possible(string str) {
    string first_inserted_string = "a"+str;
    // cout<<first_inserted_string<<'\n';
    if(check_string_unpalindrom(first_inserted_string)) return first_inserted_string;
    for(int i=1;i<str.size();i++) {
        string pre_string = parse_string(str, 0, i);
        string post_string = parse_string(str, i, str.size());
        string test_string = pre_string+"a"+post_string;
        // cout<<test_string<<'\n';
        if(check_string_unpalindrom(test_string)) return test_string;
    }
    string last_inserted_string = str+"a";
    // cout<<last_inserted_string<<'\n';
    if(check_string_unpalindrom(last_inserted_string)) return last_inserted_string;
    return "";
}

string parse_string(string str, int st, int end) {
    string tmp = "";
    for(int i=st;i<end;i++) {
        tmp = tmp + str[i];
    }
    return tmp;
}

bool check_string_unpalindrom(string str) {
    for(int i=0;i<str.size()/2;i++) {
        if(str[i]!=str[str.size()-i-1]) {
            return true;
        }
    }
    return false;
}