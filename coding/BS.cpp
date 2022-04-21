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

