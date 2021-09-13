#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int arr[8001] = {0,};
vector<pair<int, int>> tmp;
int main() {
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int sum = 0;
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        sum = sum + tmp;
        min_num = min(min_num, tmp);
        max_num = max(max_num, tmp);
        arr[(tmp+4000)]++;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    cout<<round((double)sum/n)<<'\n';
    cout<<v[v.size()/2]<<'\n';
    // cout<<"hi1"<<'\n';
    // cout<<arr[0]<<'\n';
    for(int i=0;i<=8000;i++) {
        // cout<<arr[i]<<' ';
        tmp.push_back(make_pair(arr[i], i-4000));
    }
    // cout<<"hi"<<'\n';
    sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
    int frequent_val = tmp[0].first;
    // cout<<"fre:" <<frequent_val<<'\n';
    vector<int> tmp_2;
    for(int i=1;i<tmp.size();i++) {
        if(tmp[i].first == frequent_val) {
            tmp_2.push_back(tmp[i].second);
        } else {
            break;
        }
    }
    sort(tmp_2.begin(), tmp_2.end());
    if(tmp_2.size()>1) {
        cout<<tmp_2[1]<<'\n';
    } else {
        cout<<tmp[0].second<<'\n';
    }    

    cout<<max_num - min_num<<'\n';
}