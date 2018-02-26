// templates

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}

// powers
ll Madd(ll a,ll b,ll mod){ll c=(ll)((ll)(a)+(ll)(b));while(c>=mod){c-=mod;};while(c<0){c+=mod;};return c;}
ll Msub(ll a,ll b,ll mod){return add(a,mod-b,mod);}
ll Mmul(ll a,ll b,ll mod){ll c=(ll)((ll)(a)*(ll)(b));c%=mod;while(c<0){c+=mod;};return c;}
ll Mpow(ll a,ll n,ll b){ll res=1;while(n){if(n&1) {res=mul(res,a,b);}a=mul(a,a,b);n>>=1;}return add(res,0,b);}
ll Mdiv(ll a,ll b,ll mod){ll ans=mul(a,mod_pow(b,mod-2,mod),mod);return ans;}

----------------------------------------------------------------------------------------------------------------------------------

// calculating nCr using lucas
 
long long SmallC(int n, int r, int MAX)
{
    vector< vector<long long> > C(2,vector<long long> (r+1,0));
 
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i&1][k] = 1;
            else
                C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MAX;
    }
    return C[n&1][r];
}
 
long long Lucas(int n, int m, int p)
{
    if (n==0 && m==0) return 1;
    int ni = n % p;
    int mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * SmallC(ni, mi, p);
}
 
long long Co(int n, int r, int MAX)
{
    return Lucas(n, r, MAX);
}
 
int main()
{
     
    int n,r,p;
    while (~scanf("%d%d%d",&n,&r,&p))
    {
          printf("%lld\n",Co(n,r,p));
    }
}

----------------------------------------------------------------------------------------------------------------------------------

// calculating nCr by inverse euler ***

ll f[20];
//f[0]=1 , f[1]=1 and condition for <0

/* This function calculates (a^b)%MOD */
ll pow(ll a, ll b, ll MAX)
{
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MAX) x%=MAX;
        }
        y = (y*y);
        if(y>MAX) y%=MAX; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n)
{
    return pow(n,MAX-2,MAX);
}
 
ll C(ll n, ll r)
{
    for (ll i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MAX;
    return (f[n]*((InverseEuler(f[r], MAX) * InverseEuler(f[n-r], MAX)) % MAX)) % MAX;
}
 
----------------------------------------------------------------------------------------------------------------------------------

// LUCAS + FERMAT ;)

ll max_fact=1;
//declare fact and fact[0]=1

/* This function calculates (a^b)%MAX */
ll pow(int a, int b, int MAX)
{
    ll x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MAX) x%=MAX;
        }
        y = (y*y);
        if(y>MAX) y%=MAX; 
        b /= 2;
    }
    return x;
}

ll fermat(ll n) { return pow(n, MAX-2); }

ll smallC(ll n, ll r)
{
	ll i;
	if (n>max_fact)
	{
		for (i=max_fact; i<=n; i++)
		{
			fact[i]=(fact[i-1]*i)%MAX;
		}
		max_fact=n;
	}
	return (fact[n]*(fermat(fact[r])*fermat(fact[n-r]))%MAX)%MAX;
}

ll lucas(ll n,ll r)	
{
	if (n==0 && r==0) return 1;
	ll ni = n%MAX;
	ll ri = r%MAX;
	if (ni<ri) return 0;
	return ( lucas(n/MAX, r/MAX)*smallC(ni, ri) );
}
 

----------------------------------------------------------------------------------------------------------------------------------
