#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
int ans = INT_MAX;

int main() {
    freopen("input.txt","r",stdin);
    int num, dest;
    cin>>num>>dest;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int start_point = 0;
    int end_point = 0;
    int now_sum = 0;
    while(end_point<=num) {
        // cout<<"now_sum: "<<now_sum<<'\n';
        if(now_sum>=dest) {
            int now_len = end_point-start_point;
            if(now_len < ans) ans = now_len;
            now_sum = now_sum - v[start_point];
            start_point++;
        } else {
            now_sum = now_sum + v[end_point];
            end_point++;
        }
    }
    if(ans==INT_MAX) cout<<0<<'\n';
    else cout<<ans<<'\n';
}