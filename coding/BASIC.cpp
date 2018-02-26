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
    	mid = lo + ((hi - lo) >> 1);
        if(a[mid-1] >= req) hi = mid - 1;
        else lo = mid + 1;
   	} return hi
}

------------------------------------------------------------------------------------------------------------------------------------------------


