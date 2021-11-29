#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<long long> vl;
typedef vector<pair<long long, long long>> vll;
typedef bool boolean;

#define ITER(n) for(int zz=0;zz<n;zz++) 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FFOR(i,j,m,n) for(int i=0;i<m;i++) for(int j=0;j<n;j++)
#define RANGE(i,s,e) for(int i=s;i<=e;i++)
#define RRANGE(i,j,s1,e1,s2,e2) for(int i=s1;i<=e1;i++) for(int j=s2;j<=e2;j++)
#define REVERSE(i,s,e) for(int i=e;i>=s;i--)
#define mp(a, b) make_pair(a,b)
#define pb push_back
#define mt make_tuple
#define _ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(15);


const int INF = 1 << 30;
int dirs[4][2] = {{-1,0}, {0, 1}, {1,0}, {0,-1}};
int knights[8][2] = {{-1,2}, {-1,-2}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {2,1}, {2,-1}};
int inline ri(istream &cin) {int n; cin >> n; return n;}
ll inline rl(istream &cin) {ll n; cin >> n; return n;}
char inline rc(istream &cin) {char ch; cin >> ch; return ch;}
string inline rs(istream &cin) {string n; cin >> n; return n;}
void split(string &line, vector<string> &v, const char delimeter = ',') { stringstream str(line); string buffer; while(getline( str, buffer, delimeter)) { v.pb(buffer); } }

int n;
int matrix[25][25];
int ans = INF;
vi first_team;
vi second_team;
void dfs(int i, int first_score, int second_score) {
    if(i == n) {
        ans = min(ans, abs(first_score - second_score));
        return;
    }
    int sum = 0;
    for(int j : first_team)
        sum += matrix[i][j] + matrix[j][i];
    first_team.pb(i);
    dfs(i + 1, first_score + sum, second_score);
    first_team.pop_back();

    sum = 0;
    for(int j : second_team)
        sum += matrix[i][j] + matrix[j][i];
    second_team.pb(i);
    dfs(i + 1, first_score, second_score + sum);
    second_team.pop_back();
}
int main() { _
    #ifdef ERICA
	    ifstream cin("input.txt");
        //ofstream cout("output.txt");
    #endif
    cin >> n;
    FFOR(i,j,n,n) cin >> matrix[i][j];
    dfs(0,0,0);
    cout << ans << '\n';
    return 0;
}