#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> items;
int dp[101][100001];
int main() {
    freopen("input.txt","r",stdin);
    int num, capacity;
    cin>>num>>capacity;
    for(int i=0;i<num;i++) {
        int a, b;
        cin>>a>>b;
        items.push_back(make_pair(a, b));
    }
    
    //first is weight, second is itemsalue
    for(int i = items[num-1].first; i <= capacity; i++) {
        dp[num-1][i] = items[num-1].second;
    }
    for(int i=num-2;i>=0;i--) {
        pair<int, int> this_pair = items[i];
        for(int j=0;j<this_pair.first;j++) {
            dp[i][j] = dp[i+1][j];
        }
        for(int j = this_pair.first; j<= capacity;j++) {
            dp[i][j] = max(this_pair.second + dp[i+1][j - this_pair.first], dp[i+1][j]);
        }
    }
    cout<<dp[0][capacity]<<'\n';

}