#include <iostream>
#include <queue>

using namespace std;

int visited[100001];
queue<int> q;
int ans;

void validate_and_push(int target, int step);

int main() {
    freopen("input.txt","r",stdin);
    int st, en;
    int step = 1;

    cin>>st>>en;
    q.push(st);
    visited[st] = step;
    while(!q.empty()) {
        step++;
        int size = q.size();
        for(int i=0;i<size;i++) {
            int front = q.front();
            if(front==en) {
                ans=step;
                break;
            }
            q.pop();
            validate_and_push(front*2, step);
            validate_and_push(front+1, step);
            validate_and_push(front-1, step);
        }
        if(ans==step) break;
    }
    cout<<ans-2<<'\n';
}

void validate_and_push(int target, int step) {
    if(target>=0 && target<=100000 && visited[target]==0) {
        q.push(target);
        visited[target]=step;
    }    
}