#include <iostream>
#include <string.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_range(int a, int b, int dest_x, int dest_y);

int arr[1001][1001] = {0,};

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        memset(arr, 0, sizeof(arr));
        int ans = 0;
        int n, m;
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<arr[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // } 
        // cout<<"==============="<<'\n';       
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j]==1) {
                    for(int p=0;p<4;p++) {
                        int sx = i+dx[p];
                        int sy = j+dy[p];
                        int tx = i+dx[(p+1)%4];
                        int ty = j+dy[(p+1)%4];
                        if(check_range(sx, sy, n, m) && check_range(tx, ty, n, m) && arr[sx][sy]==1 && arr[tx][ty]==1) {
                            // cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<'\n';
                            //increase to dx[p],dy[p]
                            int now_len = 0;
                            int now_len_short = 0;
                            int fl = 0;
                            while(check_range(sx, sy, n, m) && arr[sx][sy]==1) {
                                if(now_len>0 && now_len%2==0) {
                                    if(check_range(tx, ty, n, m) && arr[tx][ty]==1) {
                                        // cout<<"s is long: "<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<'\n';
                                        ans++;
                                        tx = tx+dx[(p+1)%4];
                                        ty = ty+dy[(p+1)%4];
                                        now_len_short++;
                                    } else {
                                        fl=1;
                                        break;
                                    }
                                }
                                sx = sx+dx[p];
                                sy = sy+dy[p];
                                now_len++;
                            }

                            if(fl==1) {
                                    ans = ans+(now_len_short-1)/2;
                            } else {
                                while(now_len_short <= now_len*2+1) {
                                    if(check_range(tx, ty, n, m) && arr[tx][ty]==1) {                                    
                                        tx = tx+dx[(p+1)%4];
                                        ty = ty+dy[(p+1)%4];
                                        now_len_short++;
                                    } else {
                                        break;
                                    }
                                }
                                // cout<<now_len_short<<'\n';
                                ans = ans+(now_len_short-1)/2;
                            } 
                               
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<k+1<<": "<<ans<<'\n';
    }
}

bool check_range(int a, int b, int dest_x, int dest_y) {
    return a>=0 && a<dest_x && b>=0 && b<dest_y;
}