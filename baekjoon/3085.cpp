#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);
int size_num = 0;
char arr[51][51];
int cal_max_count() {
    set<int> s;
    int count = 1;
    for(int i=0;i<size_num;i++) {
        for(int j=0;j<size_num-1;j++) {
            if(arr[i][j]==arr[i][j+1]) {
                count++;
            } else {
                count = 1;
            }
            s.insert(count); 
        }
        count = 1;
    }
    count=1;
    for(int j=0;j<size_num;j++) {
        for(int i=0;i<size_num-1;i++) {
            if(arr[i][j]==arr[i+1][j]) {
                count++;
            } else {
                count = 1;
            }
            s.insert(count);            
        }
        count = 1;
    }
    int max_count = 0;
    for(auto it=s.begin();it!=s.end();it++) {
        max_count = max(max_count, *it);
    }
    return max_count;
}

void print() {
    for(int i=0;i<size_num;i++) {
        for(int j=0;j<size_num;j++) {
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int swap_and_count(int a, int b, int c, int d) {
    // cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    // cout<<arr[a][b]<<' '<<arr[c][d]<<'\n';
    // print();
    // char tmp = arr[a][b];
    // arr[a][b] = arr[c][d];
    // arr[c][d] = tmp;
    swap(arr[a][b], arr[c][d]);
    // print();
    int ret = cal_max_count();
    // tmp = arr[a][b];
    // arr[a][b] = arr[c][d];
    // arr[c][d] = tmp;
    swap(arr[a][b], arr[c][d]);
    // print();
    // cout<<ret<<'\n';
    // cout<<'\n';
    return ret;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>size_num;
    for(int i=0;i<size_num;i++) {
        for(int j=0;j<size_num;j++) {
            cin>>arr[i][j];
        }
    }

    int ans = cal_max_count();

    if(ans==size_num) {
        cout<<ans<<'\n';
        return 0;
    }

    for(int i=0;i<size_num;i++) {
        for(int j=0;j<size_num-1;j++) {
            int this_max = swap_and_count(i, j, i, j+1);
            if(this_max>ans) ans = this_max;
        }
    }
    if(ans==size_num) {
        cout<<ans<<'\n';
        return 0;
    }
    for(int j=0;j<size_num;j++) {
        for(int i=0;i<size_num-1;i++) {
            int this_max = swap_and_count(i, j, i+1, j);
            if(this_max>ans) ans = this_max;          
        }
    }

    cout<<ans<<'\n';
}