#include <iostream>
#include <algorithm>

using namespace std;

string check(string s, char plus_target);

int main() {
    freopen("input.txt","r",stdin);
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int a=0, b=0, c=0;
        string ans = "";
        string s;
        cin>>s;
        // cout<<s<<'\n';
        for(int j=0;j<s.size();j++) {
            char ch = s[j];
            if(ch=='A') {
                a++;  
            } else if(ch=='B') {
                b++;
            } else if(ch=='C') {
                c++;
            }
        }
        int max_num = max(a, max(b,c));
        // cout<<max_
        if(a+b+c != 2*max_num) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(a==max_num) {
            ans = check(s, 'A');
        }
        if(ans!="YES" && b==max_num) {
            ans = check(s, 'B');
        }
        if(ans!="YES" && c==max_num) {
            ans = check(s, 'C');
        }
        cout<<ans<<'\n';
    }
}

string check(string s, char major_char) {
    int sum = 0;
    if(s[0]==major_char) {
        for(int i=0;i<s.size();i++) {
            if(s[i]==major_char) {
                sum++;
            } else {
                sum--;
            }
            if(sum<0) return "NO";
        }
        return "YES";
    } else {
        for(int i=0;i<s.size();i++) {
            if(s[i]==major_char) {
                sum--;
            } else {
                sum++;
            }
            if(sum<0) return "NO";
        }
        return "YES";
    }
}