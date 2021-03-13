#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<char, long long> m;
vector<pair<long long, char>> v;
long long ten_pow_arr[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main() {
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        string str;
        cin>>str;
        for(int j=0;j<str.size();j++) {
            char ch = str[j];
            m[ch] = m[ch] + ten_pow_arr[str.size()-j-1];
        }
    }
	for(auto it = m.begin(); it != m.end(); it++){
        v.push_back(make_pair(it->second, it->first));
		// cout << "key: " << it->first << " " << "value: " << it->second << '\n';
	}
    sort(v.begin(), v.end(), greater<pair<long long, char>>());
    int assign_num = 9;
    int ans = 0;
    for(int i=0;i<v.size();i++) {
        pair<long long, char> p = v[i];
        ans = ans + p.first*assign_num;
        assign_num--;
        // cout<<p.first<<' '<<p.second<<'\n';
    }
    cout<<ans<<'\n';


}