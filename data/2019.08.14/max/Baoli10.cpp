#include<cstdio>
#include<algorithm>
#define ls p << 1
#define rs p << 1 | 1
#define rt 1, 1, Q
const int N = 1e5 + 10, P = 1e9 + 7;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(f == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int t[N], mn[N], c[N], b[N], l[N], r[N], x[N], y[N], p[N], B[N], Q, n, m, k;
bool a[N];
struct D {int l, r;} q[N];
void Work() {
	int xx = 1;
	for(int i = 1;i <= m; ++i) xx = 1LL * xx * (a[i] ? p[i] : (1 - p[i])) % P;
	for(int i = 1;i <= n; ++i) mn[i] = 0;
	for(int i = 1;i <= m; ++i) {
		if(a[i]) {
			if(!mn[x[i]]) mn[x[i]] = y[i];
			else mn[x[i]] = std::min(mn[x[i]], y[i]);
		}
	}
	for(int i = 1;i <= Q; ++i) {
		int r = 0;
		for(int k = q[i].l; k <= q[i].r; ++k) r = std::max(r, mn[k]);
		B[i] = (B[i] + 1LL * xx * r) % P;
	}
}
void Cal(int x) {
	if(x > m) return Work();
	a[x] = 0; Cal(x + 1); a[x] = 1; Cal(x + 1);
}
int main() {
	freopen("max.in","r",stdin);
	freopen("Baoli10.out","w",stdout);
	n = ri(); m = ri(); k = ri(); Q = ri();
	for(int i = 1;i <= m; ++i)
		x[i] = ri(), y[i] = ri(), p[i] = ri();
	for(int i = 1;i <= Q; ++i) q[i].l = ri(), q[i].r = ri();
	Cal(1); int A = 0;
	for(int i = 1;i <= Q; ++i) A = (A + B[i]) % P;
	printf("%d\n", (A + P) % P);
	return 0;
}
