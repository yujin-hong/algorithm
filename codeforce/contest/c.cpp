#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int num;
        int ans_arr[101][101] = {0,};
        cin>>num;
        if(num==2) {
            cout<<-1<<'\n';
            continue;
        } else if (num==3) {
            cout<<2<<' '<<9<<' '<<7<<'\n';
            cout<<4<<' '<<6<<' '<<3<<'\n';
            cout<<1<<' '<<8<<' '<<5<<'\n';
            continue;
        }
        int fill_num = 1;
        for(int i=0;i<num;i++) {
            for(int j=0;j<num;j=j+2) {
                ans_arr[i][j] = fill_num++;
            }
        }
        for(int i=0;i<num;i++) {
            for(int j=1;j<num;j=j+2) {
                ans_arr[i][j] = fill_num++;
            }
        }        
        for(int i=0;i<num;i++) {
            for(int j=0;j<num;j++) {
                cout<<ans_arr[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}
