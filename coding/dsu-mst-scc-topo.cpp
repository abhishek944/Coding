// ( UNION - FIND ) & ( PATH - COMPRESSION ) (1)

int c;									
int Rank[N];
int parent[N];

int assign(int m) { 									//path-compression 
    if(parent[m]==m) return m;
    return parent[m]=assign(parent[m]);
}
void Merge(int x,int y) {								// Union-find
	int xroot=assign(x);
	int yroot=assign(y);
	if(xroot!=yroot) {
		c--;											// no of components
		if(Rank[xroot] < Rank[yroot])	parent[xroot]=yroot;
		else if(Rank[xroot] > Rank[yroot]) parent[yroot]=xroot;
		else {
			Rank[xroot]++;
			parent[yroot]=xroot;
		}
	}
}

int main()
{
	Nitro;
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , n) parent[i] = i;
	c=n;
	FOR(i , 1 , e) {
		int u , v;
		cin >> u >> v;
		Merge(u , v);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ( UNION - FIND ) & ( PATH - COMPRESSION ) (2)

int c;
int Rank[N];
int parent[N];
int dsize[N];

int assign(int m) { 									//path-compression 
    if(parent[m]==m) return m;
    return parent[m]=assign(parent[m]);
}
void addsize(int x,int y) {
	dsize[x] += dsize[y];
	dsize[y] = 0;
}
void Merge(int x,int y) {								// Union-find
	int xroot=assign(x);
	int yroot=assign(y);
	if(xroot!=yroot) {
		c--;											// no of components
		if(Rank[xroot] < Rank[yroot])	{ parent[xroot]=yroot; addsize(yroot , xroot); } 
		else if(Rank[xroot] > Rank[yroot])	{ parent[yroot]=xroot; addsize(xroot , yroot); }
		else {
			Rank[xroot]++;
			parent[yroot]=xroot;
			addsize(xroot , yroot);
		}
	}
}

int main()
{
	Nitro;
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , n) {
		parent[i] = i;
		dsize[i] = 1;
	}
	c = n;
	FOR(i , 1 , e) {
		int u , v;
		cin >> u >> v;
		Merge(u , v);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MST - kruskal 

int c;
int Rank[N];
int parent[N];
vector < pair < int , int > > st;
int mst = 0;
vector < pair < int , pair < int , int > > > vi;

int assign(int m) { 									//path-compression 
    if(parent[m]==m) return m;
    return parent[m]=assign(parent[m]);
}
void Merge(int x,int y,int w) {							// Union-find
	int xroot=assign(x);
	int yroot=assign(y);
	if(xroot!=yroot) {
		mst += w;
		st.pb({x , y});
		c--;											// no of components
		if(Rank[xroot] < Rank[yroot])	parent[xroot]=yroot;
		else if(Rank[xroot] > Rank[yroot]) parent[yroot]=xroot;
		else {
			Rank[xroot]++;
			parent[yroot]=xroot;
		}
	}
}
int main()
{
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , n) parent[i] = i;
	c = n;
	int s , d , w;
	FOR(i , 1 , e) {									// weight - (u - v) formula					
		cin >> s >> d >> w;
		vi.pb({w , {s , d}});
	}
	sort(vi.begin() , vi.end());
	FOR(i , 1 , e) {
		Merge(vi[i].ss.ff , vi[i].ss.ss , vi[i].ff);
	}
	cout << "mst = " << mst << endl;
	for(auto i : st) {
		cout << i.ff << " " << i.ss << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// MST - Prim's

#define pii pair < int , int > 
vector < pair < int , pair < int , int > > > vi;
vector < pair < int , int > > adj[N];
bool ok[N];

struct cmp {
	bool operator() (const pair < int , int > &xx , const pair < int , int > &yy) {
		return xx.ff > yy.ff;
	}
};
void primsMST() {
	int mst = 0;
	priority_queue < pair < int , int > , vector < pair < int , int > > , cmp > pq;
	pq.push({0 , 1});						// weight - edge format
	while(!pq.empty()) {
		pair < int , int > tmp = pq.top();
		pq.pop();
		if(ok[tmp.ss]) continue;
		mst += tmp.ff;
		for(auto i : adj[tmp.ss]) {
			if(!ok[i.ss]) pq.push({i.ff , i.ss});
		}
		ok[tmp.ss] = 1;
	}
	cout << "mst = " << mst << endl;
}
int main()
{
	Nitro; openup; //closeup;
	int n , m;
	cin >> n >> m;
	int x , y , w;
	FOR(i , 1 , m ) {
		cin >> x >> y >> w;
		vi.pb({w , {x , y}});
		adj[x].pb({w , y});
		adj[y].pb({w , x});
	}
	primsMST();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// strongly connected components - kosarajju's

vector < int > adj1[N] , adj2[N];
bool ok[N];
stack < int > sk;

void toposort(int u) {
	if(ok[u]) return ;
	ok[u] = 1;
	for(auto i : adj1[u]) toposort(i);
	sk.push(u);
}
void dfs2(int u) {
	if(ok[u]) return ;
	ok[u] = 1;
	for(auto i : adj2[u]) dfs2(i);
	cout << u << " ";
}
int main()
{
	Nitro; openup; //closeup;
	int n , e;
	cin >> n >> e;
	int u , v;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		adj1[u].pb(v);
		adj2[v].pb(u);
	}
	FOR(i , 0 , n-1) if(!ok[i]) toposort(i);
	fill(ok , 0);
	//while(!sk.empty()) { cout << sk.top() << " "; sk.pop(); } cout << endl;
	while(!sk.empty()) {
		int u = sk.top();
		sk.pop();
		if(ok[u]) continue;
		dfs2(u);
		cout << endl;	
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//	TOPOSORT - 1		// first print all its child nodes format

bool ok[N];
vector < int > adj[N];
vector < int > vi;

void toposort(int u) {
	if(ok[u]) return ;
	ok[u] = 1;
	for(auto i : adj[u]) toposort(i);
	vi.pb(u);
}

int main()
{
	Nitro; openup; closeup;
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , e) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	FOR(i , 1 , n) if(!ok[i]) toposort(i);
	FOR(i , 1 , n) cout << vi[i-1] << " "; cout << endl;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TOPOSORT - 2			// first print all child nodes format

vector < int > adj[N];
int indegree[N];
vector < int > vi;

void toposort(int n) {
	queue < int > q;
	FOR(i , 1 , n) if(!indegree[i]) q.push(i);
	while(!q.empty()) {
		int k = q.front();
		vi.pb(k);
		q.pop();
		for(auto i: adj[k]) {
			indegree[i]--;
			if(!indegree[i]) q.push(i);
		}
	}
	if(vi.sz!=n) { cout << "Cycle" << endl; return; }
	reverse(vi.begin() , vi.end());
	FOR(i , 1 , n) cout << vi[i-1] << " "; cout << endl;
}

int main()
{
	Nitro; openup; closeup;
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , n) indegree[i] = 0;
	FOR(i , 1 , e) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		indegree[v]++;
	}
	toposort(n);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TOPOSORT - 3 		// Job x is done before job y format

// Job x tobe done before Job y 	=>	x->y	=>	adj[x].pb(y)	=> indegree[y]++

// lexographical toposort

void lexotoposort() {
	priority_queue < int , vector < int > , greater < int > > pq;
	FOR(i , 1 , n) if(!indegree[i]) pq.push(i);
	while(!pq.empty()) {
		int u = pq.top();
		pq.pop();
		vi.pb(u);
		for(auto i : adj[u]) {
			indegree[i]--;
			if(!indegree[i]) pq.push(i);
		}
	}
	if(vi.sz!=n) { cout << "Cyclic" << endl; return; }
	FOR(i , 1 , n) cout << vi[i-1] << " "; cout << endl;
}

int main()
{
	Nitro; openup; closeup;
	int n , e;
	cin >> n >> e;
	FOR(i , 1 , n) indegree[i] = 0;
	FOR(i , 1 , e) {
		int u , v;
		cin >> u >> v;
		adj[u].pb(v);
		indegree[v]++;
	}
	lexotoposort(n);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


