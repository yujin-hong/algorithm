#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

bool prime[10001];
bool visited[10001];

void mark_prime() {
    for(int i=2;i<10001;i++) {
        if(prime[i] == false) {
            for(int j=i*i;j<10001;j=j+i) {
                prime[j] = true;
            }
        }
    }
    for(int i=2;i<10001;i++) {
        prime[i] = !prime[i];
    }
}

int change(int a, int digit, int b) {
    // cout<<a<<' '<<digit<<' '<<b<<'\n';
    if(digit==0 && b==0) return -1;
    string s = to_string(a);
    if(s[digit] == b+'0') return -1;
    s[digit] = b+'0';
    return stoi(s);
}
int bfs(int st, int en) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(st);
    visited[st] = true;
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        for(int k=0;k<qsize;k++) {
            int front = q.front(); q.pop();
            // cout<<"front: "<<front<<'\n';
            if(front == en) return step;
            for(int i=0;i<4;i++) {
                for(int j=0;j<10;j++) {
                    // cout<<"try to change"<<'\n';
                    int res = change(front, i, j);
                    if(res == -1) continue;
                    if(prime[res] && visited[res] == false) {
                        q.push(res);
                        visited[res] = true;
                    }
                }
            }
        }
        step++;
    }
    return -1;
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    mark_prime();
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int st, en;
        cin>>st>>en;
        int res = bfs(st, en);
        if(res == -1) {
            cout<<"Impossible"<<'\n';
        } else {
            cout<<res<<'\n';
        }
    }
}