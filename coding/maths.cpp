// BIT MANIPULATIONS

template <class type> class BITmanip {
public:
    inline type two(type n) { return 1 << n; }
    inline type test(type n, int b) { return (n>>b)&1; }		// returs true or false
    inline type set_bit(type & n, int b) { n |= two(b); }
    inline type unset_bit(type & n, int b) { n &= ~two(b); }
    inline type last_bit(type n) { return n & (-n); }			// returns value not place
    inline type ones(type n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }	//no of set bits
};
BITmanip < ll > bt;

--------------------------------------------------------------------------------------------------------------------------------

// number of factors
int Factors(int n) {
    if(n==1) return 1;
    int cnt = 0;
    int i = 2;
    while(i*i < n) {
        if(n%i==0) cnt += 2;
        i++;
    }
    if(i*i==n) cnt++;
    return cnt + 2;
}

// get all factors
vector < int > getFactors(int n) {
	vector < int > tmp;	
	if(n==1) {
		tmp.pb(1);
		return tmp;
	}
	tmp.pb(1); tmp.pb(n);
	int i = 2;
	while(i*i < n) {
		if(n%i == 0) {
			tmp.pb(i);
			tmp.pb(n/i);
		}
		i++;
	}
	if(i*i==n) tmp.pb(i);
	return tmp;
}

// factors for range
int factors[N];
void CountFactors(int n) {
	FOR(i , 1 , n) {
		for(int j = i;j <= n;j += i)
			factors[j]++;
	}
}

// number of prime factors
int PrimeFactors(int n) {
	if(n==1) return 1;
	int cnt = 0 , i = 2;
	while(i*i <= n) {
		while(n%i==0) {
			cnt++;
			n/=i;
		}
		i++;
	}
	if(n!=1) cnt++;
	return cnt;
}

--------------------------------------------------------------------------------------------------------------------------------

//NcR TABLE:
ll ncr[N][N];	
void NCRtable(int n) {
	FOR(i , 0 , n) ncr[i][0] = 1;
	FOR(i , 1 , n) FOR(j , 1 , i) ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
}

// NcR single calculation
ll NCR(int n , int r) {
	if(n < 0 || r < 0) return -1;
	if(n < r) return 0;
    ll result = 1;
    if(r > n/2) r = n-r;
    FOR(i , 0 , r - 1) {
        result *= (n-i);
        result /= (i+1);
    }
    return result;
}

--------------------------------------------------------------------------------------------------------------------------------



--------------------------------------------------------------------------------------------------------------------------------

// GCD:

int gcd(int a,int b) {
    if(b==0)return a;
    return gcd(b,a%b);
}

ll lcm = 1;
for(int i=1;i<=n;i++) {
	lcm = ((ll)(i) * (ll)(lcm) ) / gcd(i,lcm);
}

--------------------------------------------------------------------------------------------------------------------------------

// 1.PRIMALITY CHECK

bool ISPRIME(ll x){if(x==1)return 0;if(x<=3)return 1;if(x%6==1||x%6==5){ll y=sqrt(x),i;for(i=2;i<=y;i++)if(x%i==0)return 0;return 1;} return 0;}

--------------------------------------------------------------------------------------------------------------------------------

//Seive of erathnoses - 1

bool isprime[N+2];
vector <int > prime;
void sieve() {
    fill(isprime, true);
    isprime[0]=0; isprime[1]=0;
    int p = sqrt(N);
    for (int i=2;i<=p;i+=1)
        if (isprime[i])
            for (int j=i+i;j<=N;j+=i)
                isprime[j] = false;
    prime.pb(2);
    for (int i=3;i<=N;i+=2)
        if (isprime[i]) prime.pb(i);
}

--------------------------------------------------------------------------------------------------------------------------------

// Seive of erathnoses - 2

int isprime[N+2];
vector <int > prime;
void sieve() {
	FOR(i , 0 , N) isprime[i] = i;
    isprime[0] = 0; isprime[1] = 0;
    int p = sqrt(N);
    FOR(i , 2 , p) {
        if(isprime[i] == i) {
            for(int j = i+i;j <= N;j += i)
                isprime[j] = i;
        }
    }
    FOR(i , 2 , N) if(isprime[i] == i) prime.pb(i);
}

--------------------------------------------------------------------------------------------------------------------------------

// euler totient function for a given range

int phi[N+2];

void euler() {
    phi[1] = 1;
    for(int i=2; i<=N; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for(int j=(i<<1); j<=N; j+=i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

--------------------------------------------------------------------------------------------------------------------------------

// extended gcd

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

--------------------------------------------------------------------------------------------------------------------------------

//fibanocci of nth number - type 1

void multiply(ll f[2][2],ll m[2][2])
{
    ll x =  Madd(Mmul(f[0][0],m[0][0],MOD),Mmul(f[0][1],m[1][0],MOD),MOD);
    ll y =  Madd(Mmul(f[0][0],m[0][1],MOD),Mmul(f[0][1],m[1][1],MOD),MOD);
    ll z =  Madd(Mmul(f[1][0],m[0][0],MOD),Mmul(f[1][1],m[1][0],MOD),MOD);
    ll w =  Madd(Mmul(f[1][0],m[0][1],MOD),Mmul(f[1][1],m[1][1],MOD),MOD);
	f[0][0] = x; f[0][1] = y; f[1][0] = z; f[1][1] = w;
}

void power(ll f[2][2],ll n)
{
    if(n==0 || n==1) return;
    ll m[2][2] = {{1,1},{1,0}}; 
    power(f, n/2);
    multiply(f, f); 
    if (n%2 != 0) multiply(f, m);
}

ll Fibanocci(ll n)		// { 0 , 1 , 1 , 2 , 3 .. }
{
    ll f[2][2] = {{1,1},{1,0}};
    if(n == 0) return 0;
    power(f, n-1);
    return f[0][0];
}

// fibanocci of nth number - type 2
// ans is x

void Fibanocci(ll n, ll&x, ll&y){
    if(n<=0) { x = 0; y = 1; return; }
    if(n&1){ Fibanocci(n-1, y, x); y=Madd(x,y,MOD);}
	else{
        ll a, b;
        Fibanocci(n>>1, a, b);
        y = Madd(Mmul(a,a,MOD),Mmul(b,b,MOD),MOD);
        x = Madd(Mmul(a,b,MOD),Mmul(a,(b-a+MOD),MOD),MOD);
    }
}

--------------------------------------------------------------------------------------------------------------------------------


