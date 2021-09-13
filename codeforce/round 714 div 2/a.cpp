#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int per_num, peak_num;
        vector<int> v;
        cin>>per_num>>peak_num;

        if(peak_num > (per_num-1)/2) {
            cout<<-1<<'\n';
            continue;
        }
        int peak_count = 0;
        for(int i=1;i<=per_num/2;i++) {
            if(peak_count>=peak_num) {
                break;
            }
            v.push_back(i);
            v.push_back(per_num+1-i);
            peak_count++;
        }
        for(int i=peak_count+1;i<per_num+1-peak_num;i++) {
            v.push_back(i);
        }
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
    }
}