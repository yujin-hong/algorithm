#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int set_num;

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int n;
    int max_num = 20;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        int num;
        cin>>s;
        // cout<<s;
        if(s=="add") {
            cin>>num;
            set_num = set_num | (1<<(num-1));
        } else if (s=="remove") {
            cin>>num;
            set_num = set_num & ~(1<<(num-1));
        } else if (s=="check") {
            cin>>num;
            int res = set_num & (1<<(num-1));
            cout<<(res!=0)<<'\n';
        } else if (s=="toggle") {
            cin>>num;
            set_num = set_num ^ (1<<(num-1));
        } else if (s=="all") {
            set_num = (1<<max_num) - 1;
        } else if (s=="empty") {
            set_num = 0;
        }
    }

}