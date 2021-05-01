#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int32_t M=1e9+7;
#define int long long
#define pb push_back
// ************************************
void solve()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int query[q];
    for(int i=0;i<q;i++)
        cin>>query[i];
    vector<int> check(51,-1);
    for(int i=0;i<n;i++)
    {
        if(check[a[i]]==-1)
            check[a[i]]=i+1;
    }
    for(int i=0;i<q;i++)
    {
        cout<<check[query[i]]<<" ";
        if(check[query[i]]!=1)
        {
            for(int j=1;j<=50;j++)
            {
                if(check[j]!=-1&&check[j]<check[query[i]])
                {
                    check[j]++;
                }
            }
            check[query[i]]=1;
        }
    }
    cout<<"\n";
    return;
}

// ************************************

signed main()
{
    fast;
    // #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    // #endif
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}