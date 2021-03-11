#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int visited[10001];
queue<pair<int, string>> q;
string bfs(int st, int dest);
string execute_D(int prev_num, string prev_string, int dest);
string execute_S(int prev_num, string prev_string, int dest);
string execute_L(int prev_num, string prev_string, int dest);
string execute_R(int prev_num, string prev_string, int dest);
string check_and_push_queue(int new_num, string new_string, int dest);

int main() {
    freopen("input.txt","r",stdin);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int a, b;
        cin>>a>>b;
        cout<<bfs(a, b)<<'\n';
        memset(visited, 0, sizeof(visited));
        queue<pair<int, string>> empty;
        swap(q, empty);
    }
}

string bfs(int st, int dest) {
    q.push(make_pair(st, ""));
    visited[st] = 1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int prev_num = q.front().first;
            string prev_string = q.front().second;
            if(prev_num==dest) {
                return prev_string;
            }
            q.pop();
            string res = execute_D(prev_num, prev_string, dest);
            if(res!="") return res;

            res = execute_S(prev_num, prev_string, dest);
            if(res!="") return res;
            
            res = execute_L(prev_num, prev_string, dest);
            if(res!="") return res;
        
            res = execute_R(prev_num, prev_string, dest);
            if(res!="") return res;
            
        }
    }
    return "";
}

string execute_D(int prev_num, string prev_string, int dest) {
    int new_num = prev_num*2%10000;
    return check_and_push_queue(new_num, prev_string+"D", dest);
}

string execute_S(int prev_num, string prev_string, int dest) {
    int new_num;
    if(prev_num==0) {
        new_num = 9999;
    } else {
        new_num = prev_num-1;
    }
    return check_and_push_queue(new_num, prev_string+"S", dest);    
}

string execute_L(int prev_num, string prev_string, int dest) {
    int remain_num = prev_num%1000;
    int leftmost_num = prev_num/1000;
    int new_num = remain_num*10 + leftmost_num;
    return check_and_push_queue(new_num, prev_string+"L", dest);    
}

string execute_R(int prev_num, string prev_string, int dest) {
    int rightmost_num = prev_num%10;
    int remain_num = prev_num/10;
    int new_num = 1000*rightmost_num+remain_num;
    return check_and_push_queue(new_num, prev_string+"R", dest);    
}

string check_and_push_queue(int new_num, string new_string, int dest) {
    if(visited[new_num]==0) {
        q.push(make_pair(new_num, new_string));
        visited[new_num]=1;
    }
    if(new_num == dest) return new_string;
    return "";
}