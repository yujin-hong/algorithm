#include <iostream>

using namespace std;

long long arr[10001][4];
int main() {
    freopen("input.txt","r",stdin);
    arr[1][1]=1;
    arr[1][2]=0;
    arr[1][3]=0;
    arr[2][1]=1;
    arr[2][2]=1;
    arr[2][3]=0;
    arr[3][1]=1;
    arr[3][2]=1;
    arr[3][3]=1;    
    for(int i=4;i<10001;i++) {
        arr[i][1] = arr[i-1][1];
        arr[i][2] = arr[i-2][1]+arr[i-2][2];
        arr[i][3] = arr[i-3][1]+arr[i-3][2]+arr[i-3][3];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int tmp;
        cin>>tmp;
        cout<<arr[tmp][1]+arr[tmp][2]+arr[tmp][3]<<'\n';
    }    
}