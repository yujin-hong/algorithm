#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int num;
        cin>>num;
        int fx=-1, fy=-1, tx=-1, ty=-1;
        for(int i=0;i<num;i++) {
            for(int j=0;j<num;j++) {
                char tmp;
                cin>>tmp;
                if(tmp == '*') {
                    if(fx==-1 && fy==-1) {
                        fx = i;
                        fy = j;
                    } else {
                        tx = i;
                        ty = j;
                    }
                }
            }
        }
        int ax=-1, ay=-1, bx=-1, by=-1;
        if(fx!=tx && fy!=ty) {
            ax = fx;
            ay = ty;
            bx = tx;
            by = fy;
        } else if(fx==tx) {
            ay = fy;
            by = ty;
            int tmpx= 0;
            for(int p=0;p<num;p++) {
                if(p!=fx) {
                    tmpx = p;
                    break;
                }
            }
            ax = tmpx;
            bx = tmpx;
        } else if(fy==ty) {
            ax = fx;
            bx = tx;
            int tmpy=0;
            for(int p=0;p<num;p++) {
                if(p!=fy) {
                    tmpy = p;
                    break;
                }
            }
            ay = tmpy;
            by = tmpy;
        }

        for(int i=0;i<num;i++) {
            for(int j=0;j<num;j++) {
                if(i==fx && j==fy) {
                    cout<<'*';
                } else if(i==tx && j==ty) {
                    cout<<'*';
                } else if(i==ax && j==ay) {
                    cout<<'*';
                } else if(i==bx && j==by) {
                    cout<<'*';
                } else {
                    cout<<'.';
                }
            }
            cout<<'\n';
        }        

    }
}