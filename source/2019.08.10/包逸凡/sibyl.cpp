#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<int , ll> pil;
typedef pair<ll , ll> pll;
#define mp make_pair
#define fi first
#define se second
const int N = 3e5 + 10;
#define SZ(a) (int)(a.size())

struct edge {
	int to , nxt;
} e[N << 1];

struct query {
	int type;
	int x , y;
} qry[N];

int n , m , q , tot;
int head[N] , tag[N] , ans[N] , add[N];
unordered_map< int , bool > M[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}

inline void addedge(int u , int v) {
	++tot;
	e[tot] = (edge){v , head[u]};
	head[u] = tot;
}
inline void solve(vector< query > Q) {
	static vector< int > pt;
	pt.clear();
	for (unsigned i = 0; i < SZ(Q); ++i) {
		if (Q[i].type == 0) {
			pt.push_back(Q[i].x);
			tag[Q[i].x] = 1;
		}
	}
	for (unsigned i = 0; i < SZ(Q); ++i) {
		if (Q[i].type == 1) {
			if (tag[Q[i].x]) ans[Q[i].x] += Q[i].y;
			for (unsigned j = 0; j < SZ(pt); ++j) {
				int to = pt[j];
				if (M[Q[i].x][to]) ans[to] += Q[i].y;
			}
		} else printf("%d\n" , ans[Q[i].x]);
	}
	for (unsigned i = 0; i < SZ(Q); ++i) {
		if (Q[i].type == 1)
			add[Q[i].x] += Q[i].y;
	}
	for (int u = 1; u <= n; ++u) {
		if (!add[u]) continue;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (!tag[v]) ans[v] += add[u];
		}
		add[u] = 0;
	}
	for (unsigned i = 0; i < SZ(Q); ++i) 
		if (Q[i].type == 0) tag[Q[i].x] = 0;
	return;
}

int main() {
	
	#ifndef evenbao
	freopen("sibyl.in" , "r" , stdin);
	freopen("sibyl.out" , "w" , stdout);
	#endif
	 
	read(n); read(m); read(q);
	for (int i = 1; i <= m; ++i) {
		int u , v;
		read(u); read(v);
		addedge(u , v);
		addedge(v , u);
		M[u][v] = M[v][u] = 1;
	}
	int bsize = sqrt(n);
	for (int i = 1; i <= q; ++i) {
		read(qry[i].type); read(qry[i].x);
		if (qry[i].type == 1) read(qry[i].y);
	}
	static vector< query > tmp; tmp.clear();
	for (int i = 1; i <= q; i += bsize) {
		tmp.clear();
		for (int j = i; j <= i + bsize - 1; ++j)
			tmp.push_back(qry[j]);	
		solve(tmp);
	}
	
	return 0;
}

