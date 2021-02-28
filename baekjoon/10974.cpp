#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> v;
    int num;
    cin>>num;
    for(int i=1;i<=num;i++) {
        v.push_back(i);
    }
    do {
        for(int i=0;i<num;i++) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
    } while(next_permutation(v.begin(), v.end()));
}