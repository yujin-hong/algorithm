#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt","r",stdin);
    int tc_num ;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int now_max_pr = 9;
        int ans = 1;
        queue<pair<int, int>> q;
        int arr[10] = {0,};
        int num_count, dest;
        cin>>num_count>>dest;
        for(int j=0;j<num_count;j++) {
            int tmp;
            cin>>tmp;
            arr[tmp]++;
            q.push(make_pair(j, tmp));
        }
        while(true) {
            while(arr[now_max_pr]==0) {
                now_max_pr--;
            }
            while(q.front().second != now_max_pr) {
                pair<int, int> front = q.front();
                q.pop();
                q.push(front);
            }
            pair<int, int> pop_el = q.front();
            // cout<<pop_el.first<<' '<<pop_el.second<<'\n';
            if(pop_el.first == dest) {
                break;
            }
            q.pop();
            ans++;
            arr[now_max_pr]--;
        }
        cout<<ans<<'\n';
    }
}