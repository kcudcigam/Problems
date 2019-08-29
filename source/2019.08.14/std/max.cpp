#include<cstdio>
#include<algorithm>
#define ls p << 1
#define rs p << 1 | 1
#define rt 1, 1, Q
const int N = 1e5 + 10, Y = 2e5 + 10, P = 1e9 + 7;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int t[N << 2], tm[N << 2], c[Y], b[Y], l[Y], r[Y], pr[Y], to[Y << 1], nx[Y << 1], Q, n, m, k, H;
void add(int x, int p) {to[++H] = 1LL * to[pr[x]] * (1 - p) % P; nx[H] = pr[x]; pr[x] = H;}
struct D {int l, r;} q[N];
struct X {int x, y, p;}p[Y];
bool cmp1(X a, X b) {return a.y < b.y;}
bool cmp2(D a, D b) {return a.l == b.l ? a.r < b.r : a.l < b.l;}
int Pow(int x, int k) {
	int r = 1;
	for(;k;x = 1LL * x * x % P, k >>= 1) if(k & 1) r = 1LL * r * x % P;
	return r;
}
void B(int p, int L, int R) {
	tm[p] = 1; if(L == R) return void(t[p] = 1);
	int m = L + R >> 1; B(ls, L, m); B(rs, m + 1, R); 
	t[p] = t[ls] + t[rs];
}
void Tag(int p, int v) {tm[p] = 1LL * tm[p] * v % P; t[p] = 1LL * t[p] * v % P;}
void Pd(int p) {if(tm[p] != 1) Tag(ls, tm[p]), Tag(rs, tm[p]), tm[p] = 1;}
void M(int p, int L, int R, int st, int ed, int v) {
	if(L == st && ed == R) return Tag(p, v);
	int m = L + R >> 1; Pd(p);
	if(st <= m) M(ls, L, m, st, std::min(ed, m), v);
	if(ed > m) M(rs, m + 1, R, std::max(st, m + 1), ed, v);
	t[p] = (t[ls] + t[rs]) % P;
}
void C(int x) {
	if(l[x] > r[x]) return ; 
	int m = Pow(1 - (to[pr[x]] - b[x]) % P, P - 2); pr[x] = nx[pr[x]]; 
	M(rt, l[x], r[x], 1LL * (1 - (to[pr[x]] - b[x]) % P) * m % P);
}
int main() {
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n = ri(); m = ri(); Q = ri(); int tp = 0;
	for(int i = 1;i <= m; ++i) {
		int x = ri(), y = ri(), px = ri();
		if(!px || !y) continue;
		p[++tp].x = x; p[tp].y = y; p[tp].p = px;
	}
	std::sort(p + 1, p + tp + 1, cmp1);
	for(int i = 1;i <= n; ++i) to[++H] = 1, pr[i] = H;
	for(int i = 1;i <= tp; ++i) add(p[i].x, p[i].p);
	for(int i = 1;i <= n; ++i) b[i] = to[pr[i]];
	for(int i = 1;i <= Q; ++i) q[i].l = ri(), q[i].r = ri();
	std::sort(q + 1, q + Q + 1, cmp2);
	int L = 1, R = 0; 
    for(int i = 1;i <= n; ++i) {
        for(;L <= R && q[L].r < i; ++L) ;
        for(;q[R + 1].l <= i && R < Q; ++R) ;
        l[i] = L; r[i] = R;
    } 
    B(rt); int A = 0; p[0].y = 0;
    for(int i = tp, j; i; i = j) {
    	for(j = i;p[j].y == p[i].y && j; --j) C(p[j].x);
    	A = (A + 1LL * t[1] * (p[i].y - p[j].y)) % P;
    }
    A = (1LL * p[tp].y * Q - A) % P;
    printf("%d\n", (A + P) % P);
	return 0;
}
