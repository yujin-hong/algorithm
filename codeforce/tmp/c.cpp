#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
    freopen("input.txt","r",stdin);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> count_map;
        unordered_map<int, long long> sum_map;
        unordered_map<int, unordered_map<int, long long>> sum_for_minus;
        set<int> s;
        vector<int> index;
        int len;
        cin>>len;
        for(int i=0;i<len;i++) {
            int tmp;
            cin>>tmp;
            index.push_back(tmp);
        }
        for(int i=0;i<len;i++) {
            int player;
            cin>>player;
            m[index[i]].push_back(player);
            if(count_map.count(index[i])==0) {
                count_map[index[i]]=1;
                sum_map[index[i]] = player;    
            } else {
                count_map[index[i]]++;
                sum_map[index[i]] = sum_map[index[i]] + player;
            }
            s.insert(index[i]);
        }
        int max_count = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            int val = *it;
            if(count_map[val]>max_count) max_count = count_map[val];
            sort(m[val].begin(), m[val].end());
            vector<int> tmp = m[val];
            long long tmp_sum = 0;
            for(int j=0;j<tmp.size();j++) {
                tmp_sum = tmp_sum + tmp[j];
                sum_for_minus[val][j+1] = tmp_sum;
            }
	    }
        for(int i=1;i<=len;i++) {
            long long plus_num = 0;
            long long minus_num = 0;
            if(i>max_count) {
                cout<<0<<' ';
                continue;
            }
            for(auto it = s.begin(); it != s.end(); it++){
                int val = *it;
                if(count_map[val]/i >= 1) {
                    plus_num = plus_num + sum_map[val];
                    int should_minus_num_count = count_map[val]%i;
                    minus_num = minus_num + sum_for_minus[val][should_minus_num_count];
                }             
            }
            cout<<plus_num-minus_num<<' ';
	    }
        cout<<'\n';  
    }
}