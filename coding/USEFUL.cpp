// next permutation

unsigned int t = v | (v - 1);
w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));

unsigned int t = (v | (v - 1)) + 1;  
w = t | ((((t & -t) / (v & -v)) >> 1) - 1);

----------------------------------------------------------------------------------------------------------------------------------
// UNIQUE

sort(vi.begin(),vi.end());
st1.erase(unique(vi.begin(),vi.end()),vi.end());

----------------------------------------------------------------------------------------------------------------------------------
// time

double tick() 
{
    static clock_t oldtick; clock_t newtick = clock();
    double diff = 1.0*(newtick - oldtick) / CLOCKS_PER_SEC;
    oldtick = newtick;
    return diff;
}

cerr << tick(); // anywhere you want - tells till then time

----------------------------------------------------------------------------------------------------------------------------------

// rand gen - 1

auto MersenneTwister() {
    srand (time(NULL));
    mt19937 rng(random_device{}());
    rng.discard(rand()%700000);
    return rng;
}
auto rng = MersenneTwister();
print rng()%num

// rand gen - 2

	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	auto rng = std::bind(std::uniform_int_distribution<int>(1,6),mt19937(seed));
	
	print rng()

----------------------------------------------------------------------------------------------------------------------------------

// subset generation - 1 (brute force)  

int lmt = (1 << n);
while(it < lmt) {
	for(int i=0;i<n;i++) {
    	if(test(it,i)) {

        }
    }
    it++;
}

----------------------------------------------------------------------------------------------------------------------------------

// merge sort and inversions

void merge(ll s,ll e, ll mid)
{
	ll i,j,k,l,m;
	i=s;
	k=s;
	l=mid+1;
	while(k<=mid && l<=e)
	{
		if(a[k]<=a[l])
		{
			b[i]=a[k];
			k++;
		}
		else
		{
			b[i]=a[l];
			l++;
		}
		i++;
	}
	if(k>mid)
	{
		for(j=l;j<=e;j++)
		{
			b[i]=a[j];
			i++;
		}
	}
	else
	{
		for(j=k;j<=mid;j++)
		{
			b[i]=a[j];
			i++;
		}
	}
	for(j=s,m=mid+1;j<=mid && m<=e;)
	{
		if(a[j]>a[m])
		{
			count=count+mid-j+1;
			m++;
		}
		else
		j++;
	}
	for(j=s;j<=e;j++)
	a[j]=b[j];
}
void operations(ll s,ll e)
{
	ll mid=(s+e)/2;
	if(s<e)
	{
		operations(s,mid);
		operations(mid+1,e);
		merge(s,e,mid);
	}
}

----------------------------------------------------------------------------------------------------------------------------------

//permutations

while(next_permutation(vi.begin() , vi.end())) {
	for(int i=0;i<n;i++) cout << vi[i] << " "; cout << endl;
}

----------------------------------------------------------------------------------------------------------------------------------

//mobius function

for (int i=1; i<=maxi; i++)
    mobius[i] = 1;
 
for (int i=2; i <= maxi; i++)
    if (ciur[i] == 0)
    {
        for (int j=i; j<=maxi; j+=i)
            ciur[j] = 1, mobius[j] = -mobius[j];
        if (i <= maxi / i)
        {
            for (int j=i * i; j<=maxi; j += i * i)
                mobius[j] = 0;
        }
    }
    
----------------------------------------------------------------------------------------------------------------------------------

// max/min of a subarray of length k

for(int i=0;i<n;i++) {
	while(!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
	while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
	dq.push_back(i);
	if(i >= k) cout << a[dq.front()] << endl;
}
----------------------------------------------------------------------------------------------------------------------------------

// BASIC

// all are 0 based

1. binary_search :
			a) if val found : return pos
			b) else return -1

2. lower_bound :
			a) if val found : return lower_pos
			b) else return upper_pos

3. upper_bound :
			a) if val found or not found : return upper_pos

positions -> 0 , 1 , 2 , 3 , . . . .  n

eg : lo = 0 , hi = n , req = m

int Bsearch(int lo,int hi,int req) {
	int mid;
	while(lo <= hi) {
    	mid = lo + ((hi-lo)>>1);
        if(a[mid-1]==req) return mid-1;
        if(a[mid-1] > req) hi = mid-1;
        else lo = mid+1;
    } return -1;
}

int UpperSearch(int lo,int hi,int req) {
	int mid;
	while(lo <= hi) {
    	mid = lo + ((hi-lo) >> 1);
        if(a[mid-1] <= req) lo = mid + 1;
        else hi = mid - 1;
   	} return hi
}

int LowerSearch(int lo,int hi,int req)  {
	int mid;
	while(lo <= hi) {
    	mid = lo + ((hi-lo) >> 1);
        if(a[mid-1] >= req) hi = mid - 1;
        else lo = mid + 1;
   	} return hi
}
