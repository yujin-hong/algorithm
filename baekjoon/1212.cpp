#include <iostream>
#include <vector>
#include <string> 
using namespace std;


void push_bin_to_vec(int ch);

int fl=0;
int main() {
    string num;
    cin>>num;
    if(num=="0") {
        cout<<0<<'\n';
        return 0;
    }
    for(int i=0;i<num.size();i++) {
        push_bin_to_vec(num[i]-48);
        fl=1;
    }
}

void push_bin_to_vec(int ch) {
    vector<int> v;
    for(int i=0;i<3;i++) {
        if(ch==0) v.push_back(0);
        else {
            v.push_back(ch%2);
            ch=ch/2;
        }
    }
    for(int i=2;i>=0;i--) {
        if(v[i]==1) fl=1;
        if(fl==1) {
            cout<<v[i];
        }
    }
}