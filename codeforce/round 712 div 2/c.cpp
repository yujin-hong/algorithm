#include <iostream>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        int len;
        cin>>len;
        string s;
        cin>>s;
        char braket[200001];
        char braket_sec[200001];
        if(len%2!=0 || !(s[0]=='1' && s[s.size()-1]=='1')) {
            cout<<"NO"<<'\n';
        } else {
            int status_0 = 0;
            int status_1 = 0;
            braket[0] = '(';
            braket[s.size()-1] = ')';
            braket_sec[0] = '(';
            braket_sec[s.size()-1] = ')';    
            int sum_1 = 0;        
            for(int j=1;j<s.size()-1;j++) {
                if(s[j]=='1') {
                    if(status_1==0) {
                        braket[j] = '(';
                        braket_sec[j] = '(';
                        status_1 = 1;
                    } else {
                        braket[j] = ')';
                        braket_sec[j] = ')';
                        status_1 = 0;
                    }
                    sum_1++;
                } else {
                    if(status_0==0) {
                        braket[j] = '(';
                        braket_sec[j] = ')';
                        status_0 = 1;
                    } else {
                        braket[j] = ')';
                        braket_sec[j] = '(';
                        status_0 = 0;
                    }
                }
            }
            if(sum_1%2!=0) {
                cout<<"NO"<<'\n';
                continue;
            }
            int val = 0;
            int fl = 1;
            for(int j=0;j<s.size();j++) {
                if(braket_sec[j]=='(') val++;
                else val--;
                if(val<0) {
                    fl = -1;
                    break;
                }
            }
            if(fl==-1) {
                cout<<"NO"<<'\n';
                continue;
            } else {
                cout<<"YES"<<'\n';
                for(int j=0;j<s.size();j++) {
                    cout<<braket[j];
                }
                cout<<'\n';

                for(int j=0;j<s.size();j++) {
                    cout<<braket_sec[j];
                }      
                cout<<'\n';

            }            
        }
    }
}