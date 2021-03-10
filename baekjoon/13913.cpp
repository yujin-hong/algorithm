#include <iostream>
#include <queue>

using namespace std;

int visited[100001];
queue<int> q;
int ans;
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
                break;
            }
            q.pop();
            validate_and_push(front*2, front, step);
            validate_and_push(front+1, front, step);
            validate_and_push(front-1, front, step);
        }
        if(ans==step-1) break;
    }
    cout<<ans-1<<'\n';
    while(ans>0) {
        ans_trace.push_back(en);
        // cout<<en<<' ';
        if(en==st) break;
        // cout<<visited[en/2]<<'\n';
        // cout<<visited[en-1]<<'\n';
        // cout<<visited[en+1]<<'\n';
        if(en%2==0 && en/2>=0 && visited[en/2]==ans-1) {
            ans--;
            en=en/2;
        } else if(en-1>=0 && visited[en-1]==ans-1) {
            ans--;
            en=en-1;
        } else if(en+1<=100000 && visited[en+1]==ans-1) {
            ans--;
            en=en+1;
        }
    }
    for(int i=ans_trace.size()-1;i>=0;i--) {
        cout<<ans_trace[i]<<' ';
    }
    // for(int i=0;i<traces_ans.size();i++) {
    //     cout<<traces_ans[i]<<' ';
    // }
}

void validate_and_push(int target, int prev, int step) {
    if(target>=0 && target<=100000 && visited[target]==0) {
        q.push(target);
        visited[target]=step;
    }    
}