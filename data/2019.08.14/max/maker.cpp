#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
const int N = 1e6 + 10;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int l[N], r[N], n, m, k, P, Q;
long long Rd() {return 1LL * rand() * rand() * rand() + 1LL * rand() * rand() + rand();}
void Rd1() {
	for(int i = 1;i <= n; ++i) l[i] = r[i] = i;
	std::random_shuffle(l + 1, l + n + 1);
	std::random_shuffle(r + 1, r + n + 1);
	for(int i =1;i <= n; ++i) if(l[i] <= r[i]) ++Q;
	printf("%d %d %d\n", n, m, Q);
	for(int i = 1;i <= m; ++i) {
		int x = Rd() % n + 1, y = Rd() % (k + 1), z = Rd() % P;
		if(Rd() % 100000 == 0) z = 1;
		if(Rd() % 100000 == 1) z = 0;
		printf("%d %d %d\n", x, y, z);
	}
	int tp = 0;
	for(int i = 1;i <= n; ++i) if(l[i] <= r[i]) l[++tp] = l[i], r[tp] = r[i];
	std::sort(l + 1, l + tp + 1); std::sort(r + 1, r + tp + 1);
	for(int i = 1;i <= tp; ++i) printf("%d %d\n", l[i], r[i]);
}
void Rd2() {
	int mid = n / 2; l[Q = 1] = 1, r[1] = mid;
	for(int i = 1;r[Q] < n && l[Q] < mid; ++i)
		r[Q + 1] = r[Q] + 1, l[Q + 1] = l[Q] + 1, ++Q;
	printf("%d %d %d\n", n, m, Q);
	for(int i = 1;i <= m; ++i) {
		int x = Rd() % n + 1, y = Rd() % (k + 1), z = Rd() % P;
		if(Rd() % 10)printf("%d %d %d\n", mid, y, z);
		if(Rd() % 100000 == 0) z = 1;
		if(Rd() % 100000 == 1) z = 0;
		printf("%d %d %d\n", x, y, z);
	}
	for(int i = 1;i <= Q; ++i) printf("%d %d\n", l[i], r[i]);
}
void Rd3() {
	Q = n;
	printf("%d %d %d\n", n, m, Q);
	for(int i = 1;i <= m; ++i) {
		int x = Rd() % n + 1, y = Rd() % (k + 1), z = Rd() % P;
		if(Rd() % 100000 == 0) z = 1;
		if(Rd() % 100000 == 1) z = 0;
		printf("%d %d %d\n", x, y, z);
	}
	for(int i = 1;i <= Q; ++i) printf("%d %d\n", i, i);
}
void Rd4() {
	Q = n - 1;
	printf("%d %d %d\n", n, m, Q);
	for(int i = 1;i <= m; ++i) {
		int x = Rd() % n + 1, y = Rd() % (k + 1), z = Rd() % P;
		if(Rd() % 100000 == 0) z = 1;
		if(Rd() % 100000 == 1) z = 0;
		printf("%d %d %d\n", x, y, z);
	}
	for(int i = 1;i < n; ++i) printf("%d %d\n", i, i + 1);
}
int main() {
	srand(time(0));
	freopen("max3.in","w",stdout);
	//freopen(.out,"w",stdout);
	n = 100, m = 500, k = 1e9, P = 1e9 + 7, Q = 0;
	Rd4();
	return 0;
}

