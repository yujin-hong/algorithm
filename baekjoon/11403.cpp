#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v[101];
int visited[101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            int tmp;
            cin>>tmp;
            if(tmp==1) {
                v[i].push_back(j);
            }
        }
    }
    //방향 그래프라 공부해야할 듯.. 플로이드 와셜이래요
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {

        }
    }
}