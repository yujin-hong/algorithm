#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

void make_prime_arr() {
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i*i<=1000000;i++) {
        for(int j=2;j*i<=1000000;j++) {
            if(arr[i*j]==0) {
                arr[i*j]=1;
            }
        }
    }

}
int main() {
    freopen("input.txt","r",stdin);
    make_prime_arr();
    int st, end;
    cin>>st>>end;
    for(int i=st;i<=end;i++) {
        if(arr[i]==0) {
            cout<<i<<'\n';
        }
    }
}