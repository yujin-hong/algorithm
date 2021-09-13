#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_roaring(int num);
string get_string(string str, int start, int size);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int test_num;
        cin>>test_num;
        while(true) {
            test_num++;
            if(check_roaring(test_num)) {
                break;
            }
        }
        cout<<"Case #"<<k+1<<": "<<test_num<<'\n';
    }
}

bool check_roaring(int num) {
    // cout<<num<<'\n';
    string num_str = to_string(num);
    int fl = 0;
    if(num_str.size() == 1) return false;
    for(int i=1;i<=num_str.size()/2;i++) {
        //check for when parsing that size
        string first_num_str="";
        for(int j=0;j<i;j++) {
            first_num_str = first_num_str+num_str[j];
        }
        int next_ind = i;
        while(true) {
            int second_check_num = stoi(first_num_str)+1;
            string second_check_num_str = to_string(second_check_num);
            // cout<<first_num_str<<' '<<second_check_num_str<<'\n';
            int second_check_num_size = second_check_num_str.size();
            string test_string = get_string(num_str, next_ind, second_check_num_size);
            // cout<<test_string<<'\n';
            if(second_check_num_str != test_string) {
                fl = 1;
                break;
            } else {
                fl=0;
            }
            first_num_str = second_check_num_str;
            next_ind = next_ind+second_check_num_size;
            if(next_ind >= num_str.size()) {
                break;
            }
        }
        if(fl == 0) {
            break;
        }
    }
    if(fl==0) {
        return true;
    }
    return false;
}

string get_string(string str, int start, int size) {
    string return_str="";
    for(int j=start;j<start+size;j++) {
        return_str = return_str+str[j];
    }
    return return_str;
}