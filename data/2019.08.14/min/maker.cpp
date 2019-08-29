#include<bits/stdc++.h>
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f  = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int n, A, B, C, D, a[1000000];
long long Rd() {1LL * rand() * rand() * rand() + 1LL * rand() * rand() + rand();}
long long fRd() {return Rd() & 1 ? -Rd() : Rd();}
double Cal(double x) {return ((A * x + B) * x + C) * x + D;}
int main() {
	freopen("min1.in","w",stdout);
	int P = 1e9;
    n = 100; A = fRd() % 3; B = fRd() % 10000; C = fRd() % 10000000; D = fRd() % P;
    for(;!A;) A = fRd() % 3;
    //A = 0; B = 0; C = -Rd() % 10000000;
    printf("%d %d %d %d %d\n", n, A, B, C, D);
    for(int i = 1;i <= n; ++i) {
    	int x = fRd() % P;
    	for(;fabs(Cal(x)) >= 1e13;) x = fRd() % P;
    	printf("%d ", x);
    }
	return 0;
}

