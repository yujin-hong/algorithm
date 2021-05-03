#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        vector<int> v;
        vector<int> possible_ans;
        vector<int> second_possible_ans;
        int num_len, max_num;
        cin>>num_len>>max_num;
        for(int i=0;i<num_len;i++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int prev = 0;
        int comp_val = v[0];
        int comp_val_ind = 0;
        int final_first_ans = 0;
        int first_ans_first_max = 0;
        int first_ans_second_max = 0;
        int final_second_ans = 0;
        for(int i=0;i<num_len;i++) {
            comp_val = v[i];
            int this_ans= 0;
            int second_ans= 0;
            if(prev == 0) {
                this_ans = comp_val-1;
            } else {
                this_ans = (comp_val-prev)/2;
                second_ans = comp_val-prev-1;
            }
            if(second_ans>final_second_ans) final_second_ans = second_ans;
            if(this_ans>first_ans_first_max) {
                first_ans_second_max = first_ans_first_max;
                first_ans_first_max = this_ans;
            } else if(this_ans>first_ans_second_max && this_ans<=first_ans_first_max) {
                first_ans_second_max = this_ans;
            }
            
            prev = comp_val;
        }
        int test_ans = max_num-prev;
        // cout<<max_num<<' '<<prev<<'\n';
        if(test_ans>first_ans_first_max) {
            first_ans_second_max = first_ans_first_max;
            first_ans_first_max = test_ans;
        } else if(test_ans>first_ans_second_max && test_ans<=first_ans_first_max) {
            first_ans_second_max = test_ans;
        }
        final_first_ans = first_ans_first_max+first_ans_second_max;
        // cout<<final_first_ans<<' '<<final_second_ans<<'\n';
        int final_ans = max(final_first_ans, final_second_ans);
        cout<<"Case #"<<k+1<<": "<<(double)final_ans/max_num<<'\n';
    }
}