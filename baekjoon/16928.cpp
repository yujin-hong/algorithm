#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[101];
int visited[101];

queue<int> q;

bool check_coord(int num) {
    return num>=0 && num<=100;
}
int bfs() {
    int ans = 0;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int size=q.size();
        for(int i=0;i<size;i++) {
            int now_ind = q.front();
            // cout<<now_ind<<'\n';
            q.pop();
            if(now_ind==100) {
                return ans;
            }

            for(int j=1;j<=6;j++) {
                if(check_coord(now_ind+j) && visited[now_ind+j]==0) {
                    visited[now_ind+j]=1;
                    int insert_ind = now_ind + j;
                    if(arr[insert_ind]==0) {
                        q.push(insert_ind);
                    } else {
                        if(visited[arr[insert_ind]]==0) {
                            visited[arr[insert_ind]] = 1;
                            q.push(arr[insert_ind]);
                        }
                    }
                }
            }
        }
        ans++;
    }
    return ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n+k;i++) {
        int st, end;
        cin>>st>>end;
        arr[st] = end;
        // cout<<st<<' '<<arr[st]<<'\n';
    }
    cout<<bfs()<<'\n';
}