#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ans = 0;
int num, des;

void go(int sum, int ind, int check_flag);

int main() {
    freopen("input.txt","r",stdin);
    cin>>num>>des;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    go(0,0,0);
    cout<<ans<<'\n';
}

void go(int sum, int ind, int check_flag) {
    if(check_flag==1 && sum==des) ans++;
    if(ind>=num) return;
    // cout<<ind<<' '<<v[ind]<<'\n';
    go(sum+v[ind], ind+1, 1);
    go(sum, ind+1, 0);
}