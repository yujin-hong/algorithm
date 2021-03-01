#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans_len, candidate_len;
vector<char> v;

void go(string str, int check_ind, int odd_count, int even_count);
bool check_odd(char c);

int main() {
    //최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음
    freopen("input.txt","r",stdin);
    cin>>ans_len>>candidate_len;
    for(int i=0;i<candidate_len;i++) {
        char tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    go("", 0, 0, 0);
}

void go(string str, int check_ind, int odd_count, int even_count) {
    if(str.size()==ans_len && odd_count>=1 && even_count>=2) {
        cout<<str<<'\n';
        return;
    }

    if(str.size()>ans_len || check_ind>=candidate_len) return;

    if(check_odd(v[check_ind])) {
        go(str+v[check_ind], check_ind+1, odd_count+1, even_count);
    } else {
        go(str+v[check_ind], check_ind+1, odd_count, even_count+1);
    }
    go(str, check_ind+1, odd_count, even_count);
}

bool check_odd(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

