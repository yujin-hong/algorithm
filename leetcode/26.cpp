#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int prev_num = v[0];
    for(int i=1;i<v.size();) {
        if(v[i]==prev_num) {
            v.erase(v.begin()+i);
        } else {
            prev_num = v[i];
            i++;
        }
    }
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<'\n';
    }
    return 0;
}