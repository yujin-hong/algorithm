#include <iostream>
#include <map>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        map<int, int> m;
        int size;
        int max_num = 0;
        cin>>size;
        for(int j=0;j<size;j++) {
            int tmp;
            cin>>tmp;
            if(m.count(tmp)==0) {
                m[tmp] = 1;
            } else {
                m[tmp]++;
            }
            if(m[tmp]>max_num) max_num = m[tmp];
        }
        if(max_num>size/2) {
            cout<<max_num-(size-max_num)<<'\n';
        } else {
            cout<<0<<'\n';
        }
    }
}