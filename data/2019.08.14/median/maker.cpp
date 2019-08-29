#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
const int N = 1e6 + 10;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int n, q, P, l1, l2, r1, r2, a[N], b[N];
long long Rd() {return 1LL * rand() * rand() * rand() + 1LL * rand() * rand() + rand();}
void Get(int &l, int &r) {
	l = Rd() % n + 1; r = Rd() % n + 1;
	if(l > r) l ^= r ^= l ^= r;
	if(Rd() % (n / 3)) {
		l = Rd() % (n / 3) + 1, r = Rd() % (n / 3) + l + (n / 3);
	}
}
int main() {
	srand(time(0));
	freopen("example_median3.in","w",stdout);
	//freopen(.out,"w",stdout);
	n = 1000; q = 1000; P = 1e3;
	printf("%d %d\n", n, q);
	for(int i = 1;i <= n; ++i) a[i] = Rd() % P;
	for(int i = 1;i <= n; ++i) b[i] = Rd() % P;
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + n + 1);
	a[n + 1] = b[n + 1] = P;
	for(int i = 1;i <= n; ++i) printf("%d ", a[i]); puts("");
	for(int i = 1;i <= n; ++i) printf("%d ", b[i]); puts("");
	for(int i = 1;i <= q; ++i) {
		if(Rd() % 100) {
			Get(l1, r1); Get(l2, r2);
			while(~(r1 - l1 + r2 - l2) & 1) Get(l2, r2);
			printf("2 %d %d %d %d\n", l1, r1, l2, r2);
		}
		else {
			int x = Rd() & 1, y = Rd() % n + 1;
			if(x == 0) {
				int z = Rd() % (a[y + 1] - a[y - 1] + 1) + a[y - 1];
				a[y] = z;
				printf("1 %d %d %d\n", x, y, z);
			}
			else {
				int z = Rd() % (b[y + 1] - b[y - 1] + 1) + b[y - 1];
				b[y] = z;
				printf("1 %d %d %d\n", x, y, z);
			}
		}
	}
	return 0;
}

