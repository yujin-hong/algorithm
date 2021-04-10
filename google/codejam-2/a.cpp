#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long pow_num_func(int num);

int main() {
    freopen("input.txt","r",stdin);
    // long long pow_nums[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        vector<string> v;
        int num_len;
        int ans = 0;
        cin>>num_len;
        for(int j=0;j<num_len;j++) {
            string tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int j=1;j<num_len;j++) {
            string first_num = v[j-1];
            string second_num = v[j];
        // cout<<"ans: "<<ans<<'\n';
            // cout<<"first_num: "<<first_num<<' ';
            int first_num_digit = first_num.size();
            int second_num_digit = second_num.size();
            // cout<<first_num_digit<<' '<<second_num_digit<<'\n';
            if(second_num_digit > first_num_digit) continue;
            // long long pow_num = pow_num_func(first_num_digit- second_num_digit);
            string candidate_pre = second_num;
            int digit_diff = first_num_digit-second_num_digit;
            for(int k=0;k<digit_diff;k++) {
                candidate_pre = candidate_pre + "0";
            }
            if(candidate_pre > first_num) {
                ans = ans + digit_diff;
                v[j] = candidate_pre;
                // cout<<"this1"<<'\n';
                continue;
            }       
            string remain_num = first_num.substr(first_num.size()-digit_diff, digit_diff);
            string candidate_1 = second_num + remain_num;
            if(candidate_1 > first_num) {
                ans = ans + digit_diff;
                v[j] = candidate_1;
                cout<<"this2"<<'\n';
                continue;
            }
            // cout<<"can1: "<<candidate_1;
            string candidate_2 = "";
            if(digit_diff > 0 ) {
                if(candidate_1[candidate_1.size()-1]!='9') {
                    // cout<<"not nine!"<<'\n';
                    // cout<<candidate_1[candidate_1.size()-1]-'0'<<'\n';
                    candidate_2 = candidate_1.substr(0, candidate_1.size()-1) + to_string(candidate_1[candidate_1.size()-1]-'0'+1);
                } else {
                    int tmp= -1;
                    for(int k=2;k<candidate_1.size();k++) {
                        if(candidate_1[candidate_1.size()-k]!='9') {
                            tmp = k;
                            break;
                        }
                    }
                    if(tmp!= -1) {
                        candidate_2 = candidate_1.substr(0, candidate_1.size()-tmp) + to_string(stoi(candidate_1.substr(candidate_1.size()-tmp, tmp))+1);
                    }
                }

                if(candidate_2!= "" && candidate_2.rfind(second_num, 0) == 0 && candidate_2 > first_num) {
                    // cout<<"can2: "<<candidate_2<<'\n';
                    ans = ans + digit_diff;
                    v[j] = candidate_2;
                    // cout<<"this3"<<'\n';
                    continue;
                }
            }

            // cout<<"can 2: "<<candidate_2<<'\n';

            string candidate_3 = candidate_pre + "0";
            ans = ans + digit_diff+1;
            v[j] = candidate_3;
                // cout<<"this4"<<'\n';
        }
        // cout<<v[v.size()-1]<<'\n';
        cout<<"Case #"<<i+1<<": "<<ans<<'\n';
    }
}

// long long pow_num_func(int num) {
//     long long ans = 1;
//     for(int i=0;i<num;i++) {
//         ans = ans * 10;
//     }
//     return ans;
// }