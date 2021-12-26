#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

vector<int> v;
int n;

int upper_bound(int num) {
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
            pos = mid+1;
            left = mid + 1;
        }
    }
    return pos;
}

int lower_bound(int num) {
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
            right = mid - 1;
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
        cout<<upper_bound(num) - lower_bound(num)<<' ';
    }
    cout<<'\n';
}