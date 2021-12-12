#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

set<tuple<int, int, int>> s;
int v[4];
queue<tuple<int, int, int>> q;
int find_ans = 0;

bool check_same(tuple<int, int, int> t) {
    auto [a, b, c] = t;
    return a==b && b==c;
}

tuple<int, int> change(int n1, int n2) {
    if(n1>n2) return make_tuple(n1-n2, n2+n2);
    if(n2>n1) return make_tuple(n1+n1, n2-n1);
    else return make_tuple(-1, -1);
}

void push_q(vector<int> v) {
    // for(int i=0;i<v.size();i++) {
    //     cout<<v[i]<<' ';
    // }
    // cout<<'\n';
    sort(v.begin(), v.end());
    auto tup = make_tuple(v[0], v[1], v[2]);
    if(s.count(tup) == 0) {
        s.insert(tup);
        q.push(tup);
    }
}
void bfs() {
    while(!q.empty()) {
        auto front = q.front();
        q.pop();        
        if(check_same(front)) {
            find_ans = 1;
            return;
        }
        auto [a,b,c] = front;
        // cout<<a<<' '<<b<<' '<<c<<'\n';
        if(a>1000 || b>1000 || c>1000) continue;
        vector<int> v;
        auto [t1, t2] = change(a, b);
        if(t1!=-1 && t2!=-1) {
            v = {t1, t2, c};
            push_q(v);
        }
        auto [t3, t4] = change(b, c);
        if(t3!=-1 && t4!=-1) {
            v = {a, t3, t4};
            push_q(v);
        }
        auto [t5, t6] = change(a, c);
        if(t5!=-1 && t6!=-1) {
            v = {t5, b, t6};
            push_q(v); 
        }
    }
}

int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int t1, t2, t3;
    int sum = 0;
    cin>>t1>>t2>>t3;
    auto first = make_tuple(t1, t2, t3);
    if(check_same(first)) {
        cout<<1<<'\n';
        return 0;
    }
    if(sum%3!=0) {
        cout<<0<<'\n';
        return 0;
    }
    q.push(first);
    s.insert(first);
    bfs();
    cout<<find_ans<<'\n';
    return 0;
}