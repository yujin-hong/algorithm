#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int num;
char arr[11][11];
int find_ans = 0;
vector<int> ans;
vector<int> v;
int sign(int i) {
    if(i > 0) return 1;
    else if(i == 0) return 0;
    else return -1;
}
int sign(char c) {
    if(c == '+') return 1;
    else if(c == '0') return 0;
    else return -1;
}

bool check_sum(int size) {
    int sum = 0;
    for(int i=size-1;i>=0;i--) {
        sum = sum + v[i];
        if(sign(sum) != sign(arr[i][size-1])) return false; 
    }    
    return true;
}

void dfs(int ind) {
    if(find_ans == 1) return;
    if(!check_sum(ind)) {
        return;
    }    
    if(ind == num) {
        ans = v;
        find_ans = 1;
        return;
    }

    if(sign(arr[ind][ind])==0) {
        v[ind] = 0;
        dfs(ind+1);
    } else {
        for(int i=1;i<=10;i++) {
            v[ind] = i*sign(arr[ind][ind]);
            dfs(ind+1);
            v[ind] = 11;               
        }
    }
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>num;
    v.assign(num, 11);
    for(int i=0;i<num;i++) {
        for(int j=i;j<num;j++) {
            cin>>arr[i][j];
        }
    }
    dfs(0);
    for(int i=0;i<num;i++) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}