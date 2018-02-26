// BIT

template <class type> class Fenwick {
public:
    type tree[N+1];
    int n;

    type get(int idx) {
        type sum = 0;
        while(idx) {
            sum += tree[idx];
            idx -= (idx&-idx);
        }
        return sum;
    }

    void update(int idx,type val) {
        while(idx <= n) {
            tree[idx] += val;
            idx += (idx&-idx);
        }
    }

    void init(int n) {
        this->n = n;
        for(int i=0;i<=n;i++) tree[i]=0;
    }
};

----------------------------------------------------------------------------------------------------------------------------------

//Segmented tree

template <class type> class SegmentTree {
public:
	type st[4 * N];		
	void init() {
		for(int i=0;i<4*N;i++) st[i] = 0;
	}
	type merge(type x, type y) {
		return x+y;
	}

	type Sborder() { return 0; }
	type Scondition(int idx) { return st[idx]; }
	type Uborder(int idx) { return st[idx]; }
	type Ucondition(int idx, int val) { return st[idx] + val; }

	type search(int qs,int qe,int s,int e,int idx)
	{
		int mid=(s+e)/2; type b;
		if(s>qe || e<qs) return Sborder();	
		if(s>=qs && e<=qe) return Scondition(idx);
		return b = merge(search(qs,qe,s,mid,idx*2+1), search(qs,qe,mid+1,e,idx*2+2));
	}

	type construct(int s,int e,int idx)
	{
		int mid=(s+e)/2;
		if(s==e) return st[idx] = a[s];
		return st[idx] = merge(construct(s,mid,idx*2+1), construct(mid+1,e,idx*2+2));
	}

	type update(int us,int ue,int s,int e,int idx,type val)
	{
		int mid=(s+e)/2;	
		if(s>ue || e<us) return Uborder(idx);
		if(s==e && s>=us && e<=ue) return st[idx] = Ucondition(idx, val);
		return st[idx] = merge(update(us,ue,s,mid,idx*2+1,val), update(us,ue,mid+1,e,idx*2+2,val));
	}
};

----------------------------------------------------------------------------------------------------------------------------------

//Lazy propagation

template <class type> class LazyTree {
public:
	type st[4 * N];    
	type lazy[4 * N]; 

	LazyTree() {
		for(int i=0;i<4*N;i++) lazy[i] = 0;
	}
	type merge(type x, type y) {
		return x+y;
	}
 
	type Sborder() { return 0; }
	type Scondition(int idx) { return st[idx]; }
	type Uborder(int idx) { return st[idx]; }
	type Ucondition(int idx) { return st[idx]; }

	void LazyUpdate(int s,int e,int idx,int val) {
		st[idx] += (e-s+1)*val;
		if(s!=e) {
			lazy[idx*2+1] += val;
			lazy[idx*2+2] += val;
		}
		lazy[idx] = 0;
	}

	type search(int qs,int qe,int s,int e,int idx)
	{
	    int mid=(s+e)/2; type b;
	    if(lazy[idx]) {
	    	LazyUpdate(s,e,idx,lazy[idx]);
	    }
	    if(s>qe || e<qs) return Sborder();    
	    if(s>=qs && e<=qe) return Scondition(idx);
	    return b = merge(search(qs,qe,s,mid,(idx*2)+1), search(qs,qe,mid+1,e,(idx*2)+2));
	}

	type construct(int s,int e,int idx)
	{
	    int mid=(s+e)/2;
	    if(s==e) return st[idx] = a[s];
	    return st[idx] = merge(construct(s,mid,(idx*2)+1), construct(mid+1,e,(idx*2)+2));
	}

	type update(int us,int ue,int s,int e,int idx,type val)
	{
	    int mid=(s+e)/2;    
	    if(lazy[idx]) {
	    	LazyUpdate(s,e,idx,lazy[idx]);
	    }
	    if(s>ue || e<us) return Uborder(idx);
	    if(s>=us && e<=ue) {
	    	LazyUpdate(s,e,idx,val);
			return st[idx] = Ucondition(idx);
	    }
	    return st[idx] = merge(update(us,ue,s,mid,(idx*2)+1,val), update(us,ue,mid+1,e,(idx*2)+2,val));
	}
};

----------------------------------------------------------------------------------------------------------------------------------

// binary search tree

#define N 100

std::vector<int>  left_(N+3,-1);
std::vector<int>  right_(N+3,-1);
std::vector<int>  parent(N+3,-1);
int a[N+3];

set <int > st;
set <int >::iterator it;

int lower(int key) {
    it = st.lower_bound(key);
    if(it==st.begin()) return -1;
    it--;
    return *it;
}

int upper(int key) {
    it = st.upper_bound(key);
    if(it==st.end()) return -1;
    return *it;
}

int main(int argc, char const *argv[])
{
    int n;
    sc(n);
    for(int i=0;i<n;i++) {
        sc(a[i]);
    }

    st.insert(a[0]);        //base condition

    for(int i=1;i<n;i++) {
        int L = lower(a[i]);
        int R = upper(a[i]);

        if(L==-1 and R==-1) assert(false);

        if(L==-1) {
            left_[R] = a[i];
            parent[a[i]] = R;
        }
        else if(R==-1) {
            right_[L] = a[i];
            parent[a[i]] = L;
        }
        else {
            if(right_[L]==-1) {
                right_[L] = a[i];
                parent[a[i]] = L;
            }
            else if(left_[R]==-1) {
                left_[R] = a[i];
                parent[a[i]] = R;
            }
        }
        st.insert(a[i]);
    }

    for(int i=0;i<n;i++) {
        cout << a[i] << " --> left = " << left_[a[i]] << " | right = " << right_[a[i]] << " | parent = " << parent[a[i]] << endl;
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------

// trie

struct trie {
	trie *child[27];
	bool is_word;

	trie *new_node() {
		trie *tmp = new trie;
		for(int i=0;i<26;i++) tmp->child[i] = NULL;
		tmp->is_word = 0; return tmp;
	}

	void addword(trie *root,string s) {
		trie *tmp = root;
		int ch;
		for(int i=0;i<s.sz;i++) {
			ch = (int)(s[i]-'a');
			if(tmp->child[ch]==NULL) tmp->child[ch] = new_node();
			tmp = tmp->child[ch];
		}
		tmp->is_word = 1;
	}

	bool findword(trie *root,string s) {
		trie *tmp = root;
		int ch;
		for(int i=0;i<s.sz;i++) {
			ch = (int)(s[i]-'a');
			if(tmp->child[ch]==NULL) return 0;
			tmp = tmp->child[ch];
		}
		return tmp->is_word;
	}

	bool isempty(trie *node) {
		for(int i=0;i<26;i++) {
			if(node->child[i]!=NULL) return 0;
		}
		return 1;
	}

	bool remove_word(trie *root,string s,int idx,int n) {
		if(idx==n) {
			root->is_word = 0;
			return 1;
		}
		int ch = (int)(s[idx]-'a');
		if(idx!=n && root->child[ch]==NULL) return 0;
		if(remove_word(root->child[ch],s,idx+1,n)) {
			if(isempty(root->child[ch])) root->child[ch]=NULL;
			return (!root->is_word);
		}
		return 0;
	}

	bool print_order(trie *root,string s) {
		if(root->is_word) {
			cout << s << endl;
		}
		for(int i=0;i<26;i++) {
			if(root->child[i]!=NULL) print_order(root->child[i],s+(char)(i+'a'));
		}
	}
};

----------------------------------------------------------------------------------------------------------------------------------



