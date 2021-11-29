#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

stack<char> st;

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
        //ofstream cout("output.txt");
    #endif
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num+1;i++) {
        string sen;
        getline(cin, sen);
        if(i==0) continue;
        // cout<<sen<<'\n';
        for(int j=0;j<sen.size();j++) {
            if(sen[j] == ' ') {
                while(!st.empty()) {
                    cout<<st.top();
                    st.pop();
                }
                cout<<' ';
            } else {
                st.push(sen[j]);
            }
        }
        while(!st.empty()) {
            cout<<st.top();
            st.pop();
        }
        cout<<'\n';        
    }
}