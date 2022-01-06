#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
int s, e;
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>s>>e;
    queue<long long> q;
    q.push(s);
    int step = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            long long top = q.front(); q.pop();
            if(top == e) {
                cout<<step<<'\n';
                return 0;
            }
            // cout<<top<<'\n';
            long long next_num = top*10 + 1;
            if(next_num <= 1000000000) {
                q.push(next_num);
            }
            long long next_num_2 = top * 2;
            if(next_num_2 <= 1000000000) {
                q.push(next_num_2);
            }
        }
        // cout<<"======="<<'\n';
        step++;
    }
    cout<<-1<<'\n';
    return 0;
}