
/* CAUTION: DONOT USE 'LONG LONG INT' for QUERY SUMS 'UNLESS SPECIFIED' */


// MO THEOREM

int a[305]; 		//by n
int score[105]={0}; //by values
int k,n;
int ans[25];   		//by t
int L,R;  			//current pos
int res=0;  		//for queries

typedef struct node
{
	int L,R;
	int i;
}node;

bool cmp(const node &x, const node &y)
{
	if((x.L/k) == (y.L/k))
		return x.R < y.R;
	else
		return (x.L/k)<(y.L/k);
}

void ad(int l)
{
	score[a[l]]++;
	if(score[a[l]]==1) res++;
}

void del(int l)
{
	score[a[l]]--;
	if(score[a[l]]==0) res--;
}

int main()
{
//	scan n;	
	k=(int)sqrt(n);
	
	for(int i=0;i<n;i++)
		sc(a[i]);

	int t;			//queries
//	scan t;

	node q[t+3];
//	scan q;

	sort(q,q+t,cmp);

	L=0;
	R=-1;
	
	for(int i=0;i<t;i++)
	{
		while(L<q[i].L)
		{
			del(L);
			L++;
		}
		while(L>q[i].L)
		{
			L--;
			ad(L);	
		}

		while(R<q[i].R)
		{
			R++;
			ad(R);
		}
		while(R>q[i].R)
		{
			del(R);
			R--;
		}

		ans[q[i].i]=res;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

