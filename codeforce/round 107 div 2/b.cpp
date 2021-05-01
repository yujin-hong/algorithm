#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int prime_num_a[9] = {2, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
    int prime_num_b[9] = {3, 13, 103, 1013, 10009, 100019, 1000033, 10000079, 100000037};

    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        int a, b, c;
        cin>>a>>b>>c;
        int gcd = prime_num_a[c-1];
        int num_a = gcd * prime_num_a[a-c];
        int num_b = gcd * prime_num_b[b-c];
        cout<<num_a<<' '<<num_b<<'\n';
    }
}