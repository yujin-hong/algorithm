#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;

bool check_coord(int tx, int ty) {
    return tx>=0 && ty>=0 && tx<n && ty<m;
}

bool check_zero() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int bfs() {
    int count = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            pair<int, int> front = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int tx = front.first + dx[i];
                int ty = front.second + dy[i];
                if(check_coord(tx, ty) && arr[tx][ty] == 0) {
                    arr[tx][ty] = 1;
                    q.push(make_pair(tx, ty));
                }
            }
        }
        if(!check_zero()) {
            return count;
        }
        count++;
    }
    return count;
}


int main() {
    freopen("input.txt","r",stdin);
    cin>>m>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    if(!check_zero()) {
        cout<<"0"<<'\n';
        return 0;
    }
    int step_count = bfs();
    if(check_zero()) {
        cout<<"-1"<<'\n';
        return 0;
    }
    cout<<step_count<<'\n';
}