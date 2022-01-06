#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
vector<int> v;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    string s;
    cin>>s;
    int sum = 0;
    for(int i=0;i<s.size();i++) {
        v.push_back(s[i]-'0');
        sum+=v[i];
    }
    if(sum%3 != 0) {
        cout<<-1<<'\n';
        return 0;
    }
    sort(v.begin(), v.end(), greater<int>());
    if(v[v.size()-1] != 0) {
        cout<<-1<<'\n';
        return 0;        
    }
    for(int i=0;i<v.size();i++) {
        cout<<v[i];
    }
    cout<<'\n';
}