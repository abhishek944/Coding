// < abhishek944 > < (0-9) (A-Z) (a-z) > < (48 , 57) , (65 , 90) , (97 , 122) >
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <functional>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define forall(it, x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define FOR(i,l,r) for(int i=l;i<r;i++)
#define RFOR(i,r,l) for(int i=r-1;i>=l;i--) 
#define endl "\n"
#define sz size()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fill(a,val) memset(a,val,sizeof(a))
#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define openup freopen("input.txt","r",stdin)
#define closeup freopen("output.txt","w",stdout);


const ld PI = 3.1415926535897932384626;
const ll MOD = 1000000000 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 0.000001;

#define pii pair<int ,int>
#define TRACE(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": ERROR---->"<<x<<endl;
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1 && arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...); }
#else
#define trace(...)
#endif

ll Nmul(ll A, ll B) { ll ret = (ll)((ll)(A)*(ll)(B)); return ret; }ll Mmul(ll a, ll b, ll mod) { ll c = Nmul(a, b); c %= mod; while (c<0) { c += mod; }; return c; }
ll Nadd(ll A, ll B) { ll ret = (ll)((ll)(A)+(ll)(B)); return ret; }ll Madd(ll a, ll b, ll mod) { ll c = Nadd(a, b); while (c >= mod) { c -= mod; }; while (c<0) { c += mod; }; return c; }
ll Nsub(ll A, ll B) { ll ret = (ll)((ll)(A)-(ll)(B)); return ret; }ll Msub(ll a, ll b, ll mod) { return Madd(a, mod - b, mod); }
ll Npow(ll A, ll p) { ll ret = 1; while (p) { if (p & 1) { ret = (ret*A); }A = (A*A); p >>= 1; }return ret; }

ll Mpow(ll a, ll n, ll b) { ll res = 1; while (n) { if (n & 1) { res = Mmul(res, a, b); }a = Mmul(a, a, b); n >>= 1; }return Madd(res, 0, b); }

ll Ndiv(ld A, ld B, bool ud) { if (B) { ld ret = (ld)(A) / (ld)(B); if (ud)return ceil(ret); return floor(ret); }return INF; }ll Mdiv(ll a, ll b, ll mod) { ll ans = Mmul(a, Mpow(b, mod - 2, mod), mod); return ans; }

/*
	problem : 
	author : T.abhishek (Handle : abhishek944)
	complexity : 
	description : 
*/


#define R 1
#define M (1000 * R) + 10
#define N M + 123

int main(int argc, char const *argv[])
{
	Nitro; openup; closeup;

	

	return 0;
}
