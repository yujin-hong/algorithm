#include <iostream>

using namespace std;

bool check(int u, int r, int d, int l);

int main() {
    freopen("input.txt","r",stdin);
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int n, u, r, d, l;
        cin>>n>>u>>r>>d>>l;
        if(u==n) {
            r--;
            l--;
        }
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(r==n) {
            u--;
            d--;
        }
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }        
        if(d==n) {
            r--;
            l--;
        }
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }        
        if(l==n) {
            u--;
            d--;
        }
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(u==n-1) {
            if(r>=1) {
                r--;
            } else {
                l--;
            }
        }
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }          
        if(r==n-1) {
            if(u>=1) {
                u--;
            } else {
                d--;
            }            
        }  
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }          
        if(d==n-1) {
            if(r>=1) {
                r--;
            } else {
                l--;
            }            
        }  
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }          
        if(l==n-1) {
            if(u>=1) {
                u--;
            } else {
                d--;
            }            
        }   
        if(!check(u, r, d, l)) {
            cout<<"NO"<<'\n';
            continue;
        }  
        cout<<"YES"<<'\n';              
    }
}

bool check(int u, int r, int d, int l) {
    return u>=0 && r>=0 && d>=0 && l>=0;
}