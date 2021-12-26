#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

vector<int> v;
int n;

int bin_search(int num) {
    int left = 0;
    int right = n;
    int pos = -1;
    while(left<=right) {
        int mid = (left+right) / 2;
        if(num < v[mid]) {
            right = mid - 1;
        } else if(num > v[mid]) {
            left = mid + 1;
        } else {
            pos = mid;
            break;
        }
    }
    return pos;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int num;
        cin>>num;
        if(bin_search(num) == -1) {
            cout<<0<<' ';
        } else {
            cout<<1<<' ';
        }
    }
    cout<<'\n';
}