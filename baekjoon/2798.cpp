#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> simul;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num, dest;
    int min_diff = INT_MAX;
    int ans=0;
    cin>>tc_num>>dest;
    for(int i=0;i<tc_num;i++) {
        if(i<3) {
            simul.push_back(0);
        } else {
            simul.push_back(1);
        }
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        for(int i=0;i<tc_num;i++) {
            if(simul[i]==0) {
                sum = sum + v[i];
            }
        }
        if(sum<=dest && dest-sum < min_diff) {
            min_diff = dest-sum;
            ans = sum;
        }
    } while (next_permutation(simul.begin(), simul.end()));
    cout<<ans<<'\n';
}