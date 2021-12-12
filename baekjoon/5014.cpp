#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

int visited[1000001];
queue<int> q;
int a, st, de, up, down;
bool check_coord(int x) {
    return x>=0 && x<=a;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int step = 0;
    int find_ans = 0;   
    int ans = 0; 
    cin>>a>>st>>de>>up>>down;
    q.push(st);
    visited[st] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int front = q.front();
            q.pop();
            if(front == de) {
                find_ans = 1;
                ans = step;
                break;
            }
            //case 1
            int tx1 = front+up;
            if(check_coord(tx1) && visited[tx1]==0) {
                visited[tx1] = 1;
                q.push(tx1);
            }
            //case 2
            int tx2 = front-down;
            if(check_coord(tx2) && visited[tx2]==0) {
                visited[tx2] = 1;
                q.push(tx2);
            }
        }
        if(find_ans) break;
        step++;
    }
    if(find_ans) {
        cout<<ans<<'\n';
    } else {
        cout<<"use the stairs"<<'\n';
    }

}