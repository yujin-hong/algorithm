#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    vector<int> v;

    cin>>num;

    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    int res = next_permutation(v.begin(), v.end());

    if(res) {
        for(int i=0;i<num;i++) {
            cout<<v[i]<<' ';
        }        
    } else {
        cout<<-1<<'\n';
    }

    // cout<<next_permutation(v.begin(), v.end())<<'\n';
}