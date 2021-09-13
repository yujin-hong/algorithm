#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int ans = 0;
        vector<int> v;
        int vec_len;
        cin>>vec_len;
        for(int i=0;i<vec_len;i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i=1;i<vec_len;i++) {
            if(v[i]!=v[i-1]) {
                ans = i;
                break;
            }
        }
        if(ans==1 && v[ans]==v[vec_len-1]) {
            ans = 0;
        }
        cout<<ans+1<<'\n';
    }
}