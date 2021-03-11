#include <iostream>
#include <queue>

using namespace std;

int visited[100001];
queue<int> q;
int ans;
int path_count = 0;
vector<int> ans_trace;

void validate_and_push(int target, int prev, int step);

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
                ans=step-1;
                path_count++;
            }
            q.pop();
            visited[front] = step-1;
            validate_and_push(front*2, front, step);
            validate_and_push(front+1, front, step);
            validate_and_push(front-1, front, step);
        }
        if(ans==step-1) break;
    }
    cout<<ans-1<<'\n';
    cout<<path_count<<'\n';
}

void validate_and_push(int target, int prev, int step) {
    if(target>=0 && target<=100000 && visited[target]==0) {
        q.push(target);
        // visited[target]=step;
    }    
}