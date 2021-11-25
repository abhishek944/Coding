/*
 input index = [0, n - 1]
 returns index = [-1, n - 1]
 If value is found -> return position
 if value is !found -> return -1
*/
int Bsearch(int lo,int hi,int req) {
    int mid;
    while(lo <= hi) {
        mid = lo + ((hi-lo)>>1);
        if(a[mid]==req) return mid;
        if(a[mid] > req) hi = mid-1;
        else lo = mid+1;
    } return -1;
}

/*
 input index = [0, n - 1]
 returns index = [0, n]
 If value is found -> return pair < 1, upper position of required value >
 If value is !found -> return pair < 0, lower position of next highest value >
*/
pair < int, int > UpperSearch(int lo,int hi,int req) {
    int mid;
    while(lo <= hi) {
        mid = lo + ((hi-lo) >> 1);
        if(a[mid] <= req) lo = mid + 1;
        else hi = mid - 1;
    }
    if (hi == -1) return {0, hi + 1};
    else if (a[hi] == req) return {1, hi};
    else return {0, hi + 1};
}

/*
 input index = [0, n - 1]
 returns index = [0, n]
 If value is found -> returns pair < 1, lower position of required value >
 If value is !found -> returns pair < 0, lower position of next highest value >
*/
pair < int , int > LowerSearch(int lo, int hi, int req) {
    int mid; int local_n = hi;
    while(lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        if(a[mid] >= req) hi = mid - 1;
        else lo = mid + 1;
    }
    if (lo == local_n + 1) return {0, lo};
    else if (a[lo] == req) return {1, lo};
    else return {0, lo};
}

------------------------------------------------------------------------------------------------------------------------------------------------
int lower_bound(int a[], int val, int n) {

    int lo = 0;
    int hi = n - 1;
    int ans = n;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid] < val) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
        }
    }
    return ans;
}

int upper_bound(int a[], int val, int n) {
    int lo = 0;
    int hi = n - 1;
    int ans = n;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (a[mid] <= val) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
        }
    }
    return ans;
}

