#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char arr[51][51];
char candidate_1[8][8];
char candidate_2[8][8];

void make_candidate() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if((i+j)%2==0) {
                candidate_1[i][j] = 'W';
                candidate_2[i][j] = 'B';
            } else {
                candidate_1[i][j] = 'B';
                candidate_2[i][j] = 'W';
            }
        }
    }
}
int check_fill_count(pair<int, int> start_point) {
    int candidate_1_diff_count = 0;
    int candidate_2_diff_count = 0;
    int sx = start_point.first;
    int sy = start_point.second;
    for(int i=sx;i<sx+8;i++) {
        for(int j=sy;j<sy+8;j++) {
            if(arr[i][j]!=candidate_1[i-sx][j-sy]) {
                candidate_1_diff_count++;
            }
            if(arr[i][j]!=candidate_2[i-sx][j-sy]) {
                candidate_2_diff_count++;
            }
        }
    }
    return min(candidate_1_diff_count, candidate_2_diff_count);
}

int main() {
    make_candidate();
    // for(int i=0;i<8;i++) {
    //     for(int j=0;j<8;j++) {
    //         cout<<candidate_1[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int i=0;i<8;i++) {
    //     for(int j=0;j<8;j++) {
    //         cout<<candidate_2[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    freopen("input.txt","r",stdin);
    int m, n;
    int ans = INT_MAX;
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=m-8;i++) {
        for(int j=0;j<=n-8;j++) {
            pair<int, int> start_point = make_pair(i,j);
            int this_min_count = check_fill_count(start_point);
            if(this_min_count<ans) {
                ans = this_min_count;
            }
        }
    }
    cout<<ans<<'\n';
}
