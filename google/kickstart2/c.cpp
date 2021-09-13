#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

    
int main() {
    bool prime[1000000001];    
    int max_prime_num = 1000000000;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=2;i<=max_prime_num;i++) {
        prime[i] = true;
    }
    prime[1] = false;

    for(int i=2;i*i<=max_prime_num;i++) {
        if(prime[i]) {
            for(int j=i*2;j<=max_prime_num;j=j+i) {
                prime[j] = false;
            }
        }
    }
    freopen("input.txt","r",stdin);
    int tc_num;
    cin>>tc_num;
    for(int k=0;k<tc_num;k++) {
        long long dest_product;
        cin>>dest_product;
        long long tmp = sqrt(dest_product);
        long long near_prime;
        long long before_near_prime;
        long long after_near_prime;
        int j = 0;
        while(1) {
            if(prime[tmp-j]) {
                near_prime = tmp-j;
                break;
            }
            j++;
        }
        j++;

        while(1) {
            if(prime[tmp-j]) {
                before_near_prime = tmp-j;
                break;
            }
            j++;
        }

        j = 1;
        while(1) {
            if(prime[tmp+j]) {
                after_near_prime = tmp+j;
                break;
            }
            j++;
        }
        cout<<"Case #"<<k+1<<": ";

        if(after_near_prime * near_prime > dest_product) {
            cout<<before_near_prime*near_prime<<'\n';
        } else {
            cout<<after_near_prime * near_prime<<'\n';
        }

        // cout<<before_near_prime<<' '<<near_prime<<' '<<after_near_prime<<'\n';
    }
}