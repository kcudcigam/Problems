#include<cstdio>
#include<algorithm>
#include<vector>
const int N = 1e5 + 10, P = 1e9 + 7;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(f == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
struct D {int l, r;} q[N];
struct X {int x, y, p;}p[N];
bool cmp1(X a, X b) {return a.y < b.y;}
std::vector<int>v[N];
int b[N], pr[N], nx[N], to[N], cr[N], tp, ans, n, m, k, Q;
int Cal(int L, int R) {
	int r = 1;
	for(int i = L;i <= R; ++i) {
		r = 1LL * r * (1 - (v[i][cr[i] - 1] - b[i])) % P;
	}
	return r;
}
void C(int x) {
	--cr[x]; ans = 0;
	for(int i = 1;i <= Q; ++i) {
		ans = (ans + Cal(q[i].l, q[i].r)) % P;
	}
}
int main() {
	freopen("max.in","r",stdin);
	freopen("Baoli30.out","w",stdout);
	n = ri(); m = ri(); k = ri(); Q = ri();
	for(int i = 1;i <= m; ++i) {
		int x = ri(), y = ri(), px = ri();
		if(!px || !y) continue;
		p[++tp].x = x; p[tp].y = y; p[tp].p = px;
	}
	std::sort(p + 1, p + tp + 1, cmp1);
	for(int i = 1;i <= n; ++i) v[i].push_back(1);
	for(int i = 1;i <= tp; ++i) v[p[i].x].push_back(1 - p[i].p);
	for(int i = 1;i <= n; ++i) {
		cr[i] = v[i].size();
		for(int j = 1;j < v[i].size(); ++j) v[i][j] = 1LL * v[i][j] * v[i][j - 1] % P;
	}
	for(int i = 1;i <= n; ++i) b[i] = v[i][cr[i] - 1];
	for(int i = 1;i <= Q; ++i) q[i].l = ri(), q[i].r = ri();
    int A = 0; p[0].y = 0;
    for(int i = tp, j; i; i = j) {
    	for(j = i;p[j].y == p[i].y && j; --j) C(p[j].x);
    	A = (A + 1LL * ans * (p[i].y - p[j].y)) % P;
    }
    A = (1LL * p[tp].y * Q - A) % P;
    printf("%d\n", (A + P) % P);
	return 0;
}
