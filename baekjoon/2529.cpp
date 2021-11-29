#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

char arr[10];
set<int> used_set;
int num;

long long max_num = 0;
string max_str;
long long min_num = __LONG_LONG_MAX__;
string min_str;
void cal_string(string s, int prev_num, int ind) {
    if(ind>=num) {
        long long long_num = stoll(s);
        if(long_num>max_num) {
            max_num = long_num;
            max_str = s;
        }
        if(long_num<min_num) {
            min_num = long_num;
            min_str = s;
        }
        return;
    }
    for(int i=0;i<10;i++) {
        if(used_set.count(i)==0) {
            if(ind==-1) {
                used_set.insert(i);
                cal_string(s+to_string(i), i, ind+1);
                used_set.erase(i);
            } else {
                if(arr[ind] == '>') {
                    if(prev_num>i) {
                        used_set.insert(i);
                        cal_string(s+to_string(i), i, ind+1);
                        used_set.erase(i);
                    }
                } else {
                    if(prev_num<i) {
                        used_set.insert(i);
                        cal_string(s+to_string(i), i, ind+1);
                        used_set.erase(i);
                    }
                }
            }
        }
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>num;
    for(int i=0;i<num;i++) {
        cin>>arr[i];
    }
    cal_string("", 0, -1);
    cout<<max_str<<'\n';
    cout<<min_str<<'\n';
}