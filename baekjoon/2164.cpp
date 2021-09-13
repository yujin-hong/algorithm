#include <iostream>
#include <bits/stdc++.h>

using namespace std;
deque<int> deq;

int main() {
    int num;
    cin>>num;
    for(int i=1;i<=num;i++) {
        deq.push_back(i);
    }
    int fl=0;
    while(deq.size()>1) {
        if(fl%2!=0) {
            int front = deq.front();
            deq.push_back(front);
        }
        deq.pop_front();
        fl++;
    }
    if(deq.size()==1) {
        cout<<deq.front()<<'\n';
    }
}