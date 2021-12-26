#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

set<long long> s;
queue<pair<long long, string>> q;

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int st, en;
    cin>>st>>en;
    if(st == en) {
        cout<<0<<'\n';
        return 0;
    }
    q.push(make_pair(st, ""));
    s.insert(st);
    while(!q.empty()) {
        auto [num, str] = q.front(); q.pop();
        if(num == en) {
            cout<<str<<'\n';
            return 0;
        }
        
        long long this_num = num*num;
        if(s.count(this_num) == 0) {
            q.push(make_pair(this_num, str+ "*"));
            s.insert(this_num);
        }

        this_num = num + num;
        if(s.count(this_num) == 0) {
            q.push(make_pair(this_num, str+ "+"));
            s.insert(this_num);
        }        

        this_num = num - num;
        if(s.count(this_num) == 0) {
            q.push(make_pair(this_num, str+ "-"));
            s.insert(this_num);
        }   

        if(num!=0) {
            this_num = num / num;
            if(s.count(this_num) == 0) {
                q.push(make_pair(this_num, str+ "/"));
                s.insert(this_num);
            }  
        }
    }
    cout<<-1<<'\n';
}