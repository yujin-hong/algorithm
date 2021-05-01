#include <iostream>
#include <vector>
#include <set>

using namespace std;

int arr[51] = {0,};
vector<int> v;
int main() {
    freopen("input.txt","r",stdin);
    int first_num, second_num;
    cin>>first_num>>second_num;

    for(int i=1;i<=first_num;i++) {
        int tmp;
        cin>>tmp;
        if(arr[tmp]==0) {
            arr[tmp] = i;
        }
        v.push_back(tmp);
    }
    for(int i=0;i<second_num;i++) {
        int test;
        cin>>test;
        set<int> s;
        int ans = arr[test];
        for(int j=0;j<51;j++) {
            if(arr[j]<ans) {
                arr[j]++;
            }
        }
        // for(int j=0;j<ans-1;j++) {
        //     if(s.count(v[j])==0) {
        //         s.insert(v[j]);
        //         arr[v[j]]++;
        //     }
        // }
        // for(int j=ans-1;j>0;j--) {
        //     v[j] = v[j-1];
        // }
        // v[0] = test;
        cout<<ans<<' ';
        arr[test] = 1;

    }
}