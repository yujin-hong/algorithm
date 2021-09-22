#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void parse_string_put_queue(int num_count, string str, deque<int> &q) {
    string num_str = str.substr(1, str.size()-2);
    char num_str_arr[num_str.length()+1];
    strcpy(num_str_arr, num_str.c_str());
    char *ptr = strtok(num_str_arr, ",");
    while (ptr != NULL)
    {
        q.push_back(stoi(ptr));
        ptr = strtok(NULL, ",");
    }
}

void make_answer(int dir, deque<int> &q) {
    cout<<"[";
    // string ans = "[";
    if(dir) {
        while(!q.empty()) {
            cout<<q.front();
            // ans = ans + to_string(q.front());
            if(q.size()>1) {
                cout<<",";
                // ans = ans + ",";
            }
            q.pop_front();
        }
    } else {
        while(!q.empty()) {
            cout<<q.back();
            // ans = ans + to_string(q.back());
            if(q.size()>1) {
                cout<<",";
                // ans = ans + ",";
            }
            q.pop_back();
        }
    }
    cout<<"]";
    // ans = ans + "]";
    // return ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int i=0;i<tc_num;i++) {
        deque<int> q;
        string s;
        cin>>s;
        int num_count;
        cin>>num_count;
        string arr_str;
        cin>>arr_str;
        parse_string_put_queue(num_count, arr_str, q);
        bool dir = 1;
        int fl = 1;
        for(int j=0;j<s.size();j++) {
            if(s[j] == 'D') {
                if(q.empty()) {
                    fl = 0;
                    break;
                } else {
                    if(dir) {
                        q.pop_front();
                    } else {
                        q.pop_back();
                    }
                }
            } else if(s[j] == 'R') {
                dir = !dir;
            }
        }
        if(fl==0) {
            cout<<"error"<<'\n';
        } else {
            make_answer(dir, q);
            cout<<'\n';
        }
    }

}