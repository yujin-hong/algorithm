#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[41];

void calc_dp() {
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    for(int i=2;i<=40;i++) {
        int this_first = dp[i-1].first+dp[i-2].first;
        int this_second = dp[i-1].second+dp[i-2].second;
        dp[i] = make_pair(this_first, this_second);
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    freopen("input.txt","r",stdin);
    calc_dp();
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int tmp;
        cin>>tmp;
        cout<<dp[tmp].first<<' '<<dp[tmp].second<<'\n';
    }
}