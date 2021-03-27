#include <iostream>
#include <vector>

using namespace std;

void swap_pos(vector<int> &ans, int swap_start_pos, int swap_end_pos);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=1;i<=tc_num;i++) {
        vector<int> ans;
        
        int n, dest;
        cin>>n>>dest;
        if(dest<n-1 || dest>=n*(n+1)/2) {
            cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<'\n';
            continue;
        }
        for(int j=0;j<n;j++) {
            ans.push_back(j+1);
        }
        // for(int j=0;j<n;j++) {
        //     cout<<ans[j]<<' ';
        // }
        // 각 step 별 조합을 찾아야함. 
        int test_one_num = n-2;
        int test_max_num = n;
        vector<int> v;
        
        // int fl =
        for(int j=0;j<n-1;j++) {
            if(dest - test_one_num >=test_max_num) {
                dest = dest-test_max_num;
                v.push_back(test_max_num);
                test_max_num--;
                test_one_num--;
            } else {
                if(dest-test_one_num>0) {
                    v.push_back(dest-test_one_num);
                }
                break;
            }
        }
        // for(int j=0;j<test_one_num;j++) {
        //     v.push_back(1);
        // }
        // for(int j=0;j<v.size();j++) {
        //     cout<<v[j]<<' ';
        // }
        for(int j=v.size()-1;j>=0;j--) {
            swap_pos(ans, n-v[j], n);
        }
        cout<<"Case #"<<i<<": ";
        for(int j=0;j<ans.size();j++) {
            cout<<ans[j]<<' ';
        }
        //v값에 따라 swap 시작 (v 크기는 n-1로 일정)
        cout<<'\n';
    }
}

void swap_pos(vector<int> &ans, int swap_start_pos, int swap_end_pos) {
    vector<int> tmp;
    for(int i=0;i<swap_start_pos;i++) {
        tmp.push_back(ans[i]);
    }
    for(int i=swap_end_pos-1;i>=swap_start_pos;i--) {
        tmp.push_back(ans[i]);
    }
    // for(int i=0;i<tmp.size();i++) {
    //     cout<<tmp[i]<<' ';
    // }
    // cout<<'\n';
    ans = tmp;
}