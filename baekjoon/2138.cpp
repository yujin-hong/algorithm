#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int st[100001];
int st_2[100001];
int en[100001];

void flip(int n) {
    st[n-1] = 1-st[n-1];
    st[n] = 1-st[n];
    st[n+1] = 1-st[n+1];
}

void flip_2(int n) {
    st_2[n-1] = 1-st_2[n-1];
    st_2[n] = 1-st_2[n];
    st_2[n+1] = 1-st_2[n+1];
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif

    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        char ch;
        cin>>ch;
        st[i] = ch-'0';
        st_2[i] = ch-'0';
    }
    for(int i=0;i<num;i++) {
        char ch;
        cin>>ch;
        en[i] = ch-'0';
    }

    //with flip first one
    int ans = 1;
    st[0] = 1-st[0];
    st[1] = 1-st[1];
    for(int i=1;i<num;i++) {
        if(st[i-1] != en[i-1]) {
            flip(i);
            ans++;
        }
    }
    if(st[num-1] != en[num-1]) ans = -1;

    int ans2 = 0;
    for(int i=1;i<num;i++) {
        if(st_2[i-1] != en[i-1]) {
            flip_2(i);
            ans2++;
        }
    }
    if(st_2[num-1] != en[num-1]) ans2 = -1;
    // cout<<ans<<' '<<ans2<<"\n";
    if(ans<0 && ans2<0) {
        cout<<-1<<'\n';
    } else if(ans < 0) {
        cout<<ans2<<'\n';
    } else if(ans2<0) {
        cout<<ans<<'\n';
    } else {
        cout<<min(ans, ans2)<<'\n';
    }
}