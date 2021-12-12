#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);

vector<int> tmp;
int visited[27];
int dict_num;
vector<string> tests;
int ans = 0;

void put_to_dict(char ch) {
    int ind = ch - 'a';
    visited[ind] = 1;
    dict_num = dict_num | (1<<ind);
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
    #endif
    int tc_num, cnt;
    cin>>tc_num>>cnt;
    for(int i=0;i<tc_num;i++) {
        string str;
        cin>>str;
        tests.push_back(str);
    }
    if(cnt<5) {
        cout<<0<<'\n';
        return 0;
    }
    put_to_dict('a');
    put_to_dict('n');
    put_to_dict('t');
    put_to_dict('i');
    put_to_dict('c');
    for(int i=0;i<26;i++) {
        if(i<cnt-5) {
            tmp.push_back(0);
        } else {
            tmp.push_back(1);
        }
    }

    do {
        int word_cnt = 0;
        int this_dict_num = dict_num;
        int already_in_dict = 0;
        for(int i=0;i<26;i++) {
            if(tmp[i]==0) {
                if(visited[i]!=0) {
                    already_in_dict = 1;
                    break;
                }
                this_dict_num = this_dict_num | (1<<i);
            }
        }
        if(already_in_dict) continue;
        for(string word : tests) {
            int is_possible = 1;
            for(char ch : word) {
                if((this_dict_num & (1<<(ch-'a')))==0) {
                    is_possible = 0;
                    break;
                }
            }
            if(is_possible) {
                word_cnt++;
            }
        }
        if(word_cnt > ans) ans = word_cnt;

    } while(next_permutation(tmp.begin(), tmp.end()));

    cout<<ans<<'\n';

}