                            // now_len = 0;
                            // sx = i+dx[p];
                            // sy = j+dy[p];
                            // tx = i+dx[(p+1)%4];
                            // ty = j+dy[(p+1)%4]; 
                            // while(check_range(tx, ty, n, m) && arr[tx][ty]==1) {
                            //     if(now_len>0 && now_len%2==0) {
                            //         if(check_range(sx, sy, n, m) && arr[sx][sy]==1) {
                            //             // cout<<"t is long: "<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<'\n';
                            //             ans++;
                            //             sx = sx+dx[p];
                            //             sy = sy+dy[p];
                            //         } else {
                            //             break;
                            //         }
                            //     }
                            //     tx = tx+dx[(p+1)%4];
                            //     ty = ty+dy[(p+1)%4];
                            //     now_len++;
                            // }  