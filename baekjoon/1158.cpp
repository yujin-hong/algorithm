#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int visited[5001];

int main() {
    int count = 1;
    int vec_len,start;
    cin>>vec_len>>start;
    int step_count = start;
    for(int i=0;i<vec_len;i++) {
        v.push_back(i+1);
    }
    int start_ind = start-1;
    cout<<"<"<<v[start_ind];
    visited[start_ind]=1;
    start_ind++;
    int add_count = 0;
    while(count<vec_len) {
        // cout<<"now num: "<<v[start_ind]<<' '<<add_count<<' '<<step_count<<'\n';
        start_ind = start_ind % vec_len;
        if(visited[start_ind]==0) {
            // cout<<"=========="<<'\n';
            add_count++;
            if(add_count==step_count) {
                visited[start_ind]=1;
                cout<<", "<<v[start_ind];
                count++;
                add_count=0;
            }
        }
        start_ind++;
        // if(count==2) break;
    }
    cout<<">"<<'\n';
}