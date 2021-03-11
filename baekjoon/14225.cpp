#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int available[2000001];
int num;

void find_available_and_check(int now_ind, int now_sum);

int main() {
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    find_available_and_check(0, 0);
    int check_ind = 1;
    while(1) {
        if(available[check_ind]==0) {
            cout<<check_ind<<'\n';
            return 0;
        }
        check_ind++;
    }
}

void find_available_and_check(int now_ind, int now_sum) {
    // cout<<now_ind<<' '<<now_sum<<'\n';
    available[now_sum] = 1;
    if(now_ind>=num) return;
    find_available_and_check(now_ind+1, now_sum+v[now_ind]);
    find_available_and_check(now_ind+1, now_sum);
}