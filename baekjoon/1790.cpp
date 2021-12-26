#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

long long n, k;

long long cal_len(int num) {
    long long this_len = 0;
    string s = to_string(num);
    int ssize = s.size();
    for(int i=0;i<ssize;i++) {
        this_len+=(9*i*pow(10, (i-1)));
    }
    this_len+=((num-pow(10, (ssize-1))+1)*ssize);
    return this_len;
}

int bin_search(int num) {
    long long start = 0;
    long long end = n;
    long long mid = (start+end)/2;
    while(start<=end) {
        // cout<<start<<' '<<end<<'\n';
        mid = (start+end)/2;
        long long res = cal_len(mid);
        // cout<<res<<'\n';
        if(res > k) {
            end = mid - 1;
        } else if(res < k) {
            start = mid + 1;
        } else {
            break;
        }
    }
    return mid;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    cin>>n>>k;
    // cout<<cal_len(n)<<'\n';
    if(k > cal_len(n)) {
        cout<<-1<<'\n';
        return 0;
    }
    int res = bin_search(k);

    if(cal_len(res) < k) {
        res = res + 1;
    }

    string s = to_string(res);
    // cout<<s<<'\n';
    // cout<<cal_len(res)<<'\n';
    // cout<<k<<'\n';

    int diff_digit = cal_len(res) - k;
    cout<<s[s.size()-1-diff_digit]<<'\n';
    // cout<<()<<'\n';
    // if(cal_len(find_num) == k) {

    // }
}