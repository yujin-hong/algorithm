#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        vector<char> v;
        int a_num, b_num;
        cin>>a_num>>b_num;
        int origin_a_num = a_num;
        int origin_b_num = b_num;
        int total_vlen = a_num+b_num;
        // cout<<a_num<<' '<<b_num<<'\n';
        for(int i=0;i<total_vlen;i++) {
            char ch;
            cin>>ch;
            if(ch=='0') {
                a_num--;
            } else if(ch=='1') {
                b_num--;
            }
            v.push_back(ch);
        }
        if(a_num<0 || b_num<0) {
            // cout<<"here"<<'\n';
            cout<<-1<<'\n';
            continue;
        }        
        if(origin_a_num%2==1 && origin_b_num%2==1) {
            cout<<-1<<'\n';
            continue;
        }
        int ans = 1;
        for(int i=0;i<total_vlen/2;i++) {
            char check_ch = v[total_vlen-1-i];
            // cout<<"check: "<<check_ch<<'\n';
            if(v[i]!=check_ch) {
                if(a_num>0 && v[i]=='?' && check_ch=='0') {
                    v[i] = '0';
                    a_num--;
                } else if(b_num>0 && v[i]=='?' && check_ch=='1') {
                    v[i] = '1';
                    b_num--;
                } else if(a_num>0 && v[i]=='0' && check_ch=='?') {
                    v[total_vlen-1-i] = '0';
                    a_num--;
                } else if(b_num>0 && v[i]=='1' && check_ch=='?') {
                    v[total_vlen-1-i] = '1';
                    b_num--;
                } else {
                    ans = -1;
                    break;
                }
            }
        }
        if(ans==-1) {
            cout<<-1<<'\n';
            continue;
        }
        if(a_num%2==1 && b_num%2==1) {
            cout<<-1<<'\n';
            continue;
        } else if(a_num%2==1) {
            if(total_vlen%2==1 && v[total_vlen/2]=='?') {
                v[total_vlen/2] = '0';
                a_num--;
            } else {
                cout<<-1<<'\n';
                continue;                 
            }
        } else if(b_num%2==1) {
            if(total_vlen%2==1 && v[total_vlen/2]=='?') {
                v[total_vlen/2] = '1';
                b_num--;
            } else {
                cout<<-1<<'\n';
                continue;                
            }
        }
        for(int i=0;i<total_vlen/2;i++) {
            if(v[i]=='?') {
                if(a_num>0 && a_num%2==0) {
                    v[i]='0';
                    v[total_vlen-1-i] = '0';
                    a_num = a_num-2;
                } else if(b_num>0 && b_num%2==0) {
                    v[i] = '1';
                    v[total_vlen-1-i] = '1';
                    b_num = b_num-2;                    
                } else {
                    ans = -1;
                    break;
                }
            }
        }
        if(ans==-1) {
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0;i<total_vlen;i++) {
            cout<<v[i];
        }
        cout<<'\n';
    }
}