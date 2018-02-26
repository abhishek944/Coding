// knuth morris pattern

class KnuthMorrisPratt {
public:
	int a[N + 1];
	string pat, txt;
	vector < int > pos;

	void LPS()
	{
		int len = 0, i = 1;
		a[0] = 0;
		int k = pat.sz;
		while (i < k)
		{
			if (pat[len] == pat[i]) { len++; a[i] = len; i++; }
			else {
				if (len) len = a[len - 1];
				else { a[i] = 0; i++; }
			}
		}
	}

	void PrintLPS() {
		int k = pat.sz;
		for (int i = 0; i < k; i++) cout << pat[i] << " "; cout << endl;
		for (int i = 0; i < k; i++) cout << a[i] << " "; cout << endl;
	}

	void KMP()
	{
		LPS();
		int i = 0;	//pattern
		int j = 0;	//text
		int k1 = txt.sz, k2 = pat.sz;
		while (j < k1)
		{
			if (pat[i] == txt[j]) { i++; j++; }
			if (i == k2)
			{
				pos.pb(j - i);
				i = a[i - 1];
			}
			else if (j<k1 && pat[i] != txt[j])
			{
				if (i) i = a[i - 1];
				else j++;
			}
		}
	}

	void PrintPos() {	//0-based indexing
		int k = pos.sz;
		for (int i = 0; i < k; i++) cout << pos[i] << " "; cout << endl;
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Z algorithm

class Zalgo {
public:
    int z[N+1];
    vector < int > pos;
    string pat,txt,A;
    int k,k1,k2;

    void Zarray() {
		pos.clear();
        A = pat + '$' + txt;
        k = A.sz; k1 = txt.sz , k2 = pat.sz;
        int L = 0, R = 0, tmp;
        z[0] = k;
        for(int i=1;i<k;i++) {
            if(i > R) {
                L = R = i;
                while(R < k && A[R-L]==A[R]) R++;
                z[i] = R-L; R--;
            }
            else {
                tmp = i-L;
                if(z[tmp] < R-i+1) z[i] = z[tmp];
                else {
                    L = i;
                    while(R < k && A[R-L]==A[R]) R++;
                    z[i] = R-L; R--;
                }
            }
        }
    }

    void PrintZ() {
        for(int i=0;i<k;i++) cout << A[i] << " "; cout << endl;
        for(int i=0;i<k;i++) cout << z[i] << " "; cout << endl;
    }

    void Zpos() {
        for(int i=0;i<k;i++) {
            if(z[i]==k2) pos.pb(i-k2-1);
        }
    }

    void PrintPos() {       // 0 based indexing
        for(int i=0;i<pos.sz;i++) cout << pos[i] << " "; cout << endl;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Longest common subsequence

class LCS {
public:
	string a, b;
	int cnt[N + 1][N + 1];
	int ln1, ln2;
	char ans[N + 1];

	int ComputeLCS() {
		ln1 = a.sz, ln2 = b.sz;
		for (int i = 0; i <= ln1; i++)
		{
			for (int j = 0; j <= ln2; j++)
			{
				if (i == 0 || j == 0) cnt[i][j] = 0;
				else if (a[i - 1] == b[j - 1]) cnt[i][j] = cnt[i - 1][j - 1] + 1;
				else cnt[i][j] = max(cnt[i - 1][j], cnt[i][j - 1]);
			}
		}
		return cnt[ln1][ln2];
	}

	void PrintLCS() {
		int idx = cnt[ln1][ln2];
		int by = idx;
		int i = ln1, j = ln2;

		while (i>0 && j>0)
		{
			if (a[i - 1] == b[j - 1])
			{
				ans[idx - 1] = a[i - 1];
				i--;
				j--;
				idx--;
			}
			else if (cnt[i - 1][j] > cnt[i][j - 1]) i--;
			else j--;
		}
		cout << by << endl;
		for (i = 0; i < by; i++) cout << ans[i]; cout << endl;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TRIE

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// anti - hash test

const int Q = 11;
const int N = 1 << Q;

char S[N];

for (int i = 0; i < N; i++)
    S[i] = 'A' + __builtin_popcount(i) % 2;
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// StringHashing

#define HK 2
class StringHash {
public:                 //5 , 13 , 89 , 233 , 1597 , 28657
    ll Nhash[N+1][HK] , exp[N+1][HK];
    const int BASE[2] = {233 , 1597};
    const int mod[2] = {1000000000+7 , 1000000000+13};
    int k; string HashS;
    void HashGen() {
        k = HashS.sz; for(int i=0;i<HK;i++) {Nhash[0][i] = 0; exp[0][i] = 1;}
        for(int i=1;i<=k;i++) {
            for(int j=0;j<HK;j++) {
                Nhash[i][j] = Madd(Mmul(Nhash[i-1][j], BASE[j] , mod[j]), (int)(HashS[i-1]-'a'+1), mod[j]);
                exp[i][j] = Mmul(exp[i-1][j], BASE[j], mod[j]);
            }
        }
    }
    ll get1(int L , int R) { return Msub(Nhash[R][0], Mmul(Nhash[L-1][0], exp[R-L+1][0], mod[0]) , mod[0]); }
    ll get2(int L , int R) { return Msub(Nhash[R][1], Mmul(Nhash[L-1][1], exp[R-L+1][1], mod[1]) , mod[1]); }
    pll get(int L, int R) {     // 1-indexing
        if(HK==1) return pll(get1(L,R),0);
        return pll(get1(L,R),get2(L,R));
    }
}A,B;
bool check(pll XX,pll YY) { return (XX.ff==YY.ff && XX.ss==YY.ss); }
int HashIndex(int L,int R) { 	// 1-indexing
    int low = L , high = R , mid;
    while(low <= high) {
        mid = (low+high) >> 1;
        if(check(A.get(L,mid),B.get(L,mid))) low = mid+1;
        else high = mid-1;
    }
    if(low-1 < L) return -1;
    return low-1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



