#include <iostream>
#include <set>

using namespace std;

int check_available_count(int j, int num);

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int num;
        cin>>num;
        int ans = 0;
        for(int j=1;j<=9;j++) {
            ans = ans + check_available_count(j, num);
        }
        cout<<ans<<'\n';
    }
}

int check_available_count(int j, int num) {
    int count = 0;
    string alone_num = to_string(j);
    while(j<=num) {
        count++;
        if(j>=100000000) {
            break;
        }
        string new_str = to_string(j)+alone_num;
        j = stoi(new_str);
    }
    return count;
}