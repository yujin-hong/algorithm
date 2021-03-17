#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int num_len;
        int samenum_count = 0;
        int arr[101] = {0,};
        vector<int> v;
        vector<int> v_samenum;
        cin>>num_len;
        for(int j=0;j<num_len;j++) {
            int tmp;
            cin>>tmp;
            if(arr[tmp]==0) {
                arr[tmp]=1;
                v.push_back(tmp);
            } else {
                v_samenum.push_back(tmp);
            }
        }
        sort(v.begin(), v.end());
        for(int j=0;j<v.size();j++) {
            cout<<v[j]<<' ';
        }
        for(int j=0;j<v_samenum.size();j++) {
            cout<<v_samenum[j]<<' ';
        }
        cout<<'\n';
    }
}