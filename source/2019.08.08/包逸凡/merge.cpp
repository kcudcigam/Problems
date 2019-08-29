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
#define MP make_pair
#define fi first
#define se second
const int N = 5e5 + 10;

int n , q;
int fa[N] , size[N] , tag[N] , res[N];
vector< int > a[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]); 
}
inline void merge(int u , int v) {
	u = find(u) , v = find(v);
	if (u == v) return;
	if (size[u] > size[v]) swap(u , v);
	fa[u] = v; size[v] += size[u];
	tag[u] -= tag[v]; 
	a[v].push_back(u);
	return;
}
inline bool bfs(int u) {
	queue< int > q;
	while (!q.empty()) q.pop();
	q.push(u);	
	res[u] = tag[u];
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (unsigned i = 0; i < a[cur].size(); ++i) {
			int v = a[cur][i];
			res[v] = res[cur] + tag[v];
			q.push(v);
		}
	}
}

int main() {
	
	#ifndef evenbao
	freopen("merge.in" , "r" , stdin);
	freopen("merge.out" , "w" , stdout);
	#endif
	
	read(n); read(q);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		size[i] = 1;
		tag[i] = 0;
		a[i].clear();
	} 
	while (q--) {
		int type , x , y;
		read(type); read(x); read(y);
		if (type == 1) merge(x , y);
		else tag[find(x)] += y;
	}
	for (int i = 1; i <= n; ++i)
		if (find(i) == i) bfs(i);
	for (int i = 1; i <= n; ++i) 
		if (i == 1) printf("%d" , res[i]);
		else printf(" %d" , res[i]);
	printf("\n");
	
	return 0;
}


