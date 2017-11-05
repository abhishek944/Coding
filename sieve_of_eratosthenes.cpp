int isprime[N+2];
void sieve() {
	for(int i = 0;i <= N; i++) isprime[i] = i;
    isprime[0] = 0; isprime[1] = 0;
    int p = sqrt(N);
    for(int i=2;i <= p;i++) {
        if(isprime[i] == i) {
            for(int j = i+i;j <= N;j += i)
                isprime[j] = i;
        }
    }
}
