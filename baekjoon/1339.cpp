#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> v;

vector<char> priority_char[11];
map<char, int> m;
long long sum = 0;

long long convert_to_num(string str);

int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++) {
            priority_char[str.size()-j].push_back(str[j]);
        }
        v.push_back(str);
    }
    int assign_num = 9;
    for(int i=10;i>0;i--) {
        vector<char> candidates = priority_char[i];
        for(int j=0;j<candidates.size();j++) {
            if(m[candidates[j]] == 0) {
                m[candidates[j]] = assign_num;
                assign_num--;
            }
        }
    }
    for(int i=0;i<v.size();i++) {
        sum = sum + convert_to_num(v[i]);
    }
    cout<<sum<<'\n';
}

long long convert_to_num(string str) {
    string num_str = "";
    for(int i=0;i<str.size();i++) {
        num_str = num_str + to_string(m[str[i]]);
    }
    // cout<<stoll(num_str)<<'\n';
    return stoll(num_str);
}