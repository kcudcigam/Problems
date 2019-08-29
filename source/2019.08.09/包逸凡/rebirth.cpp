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
#define mp make_pair
#define fi first
#define se second
const ll INF = 1e18;
const int N = 2e5 + 10;

struct edge {
	int to , w , id;
} e[N << 1];

int n , m , ban , size;
int lc[N * 60] , rc[N * 60] , rt[N];
ll mx[N * 60];
vector< edge > a[N];
ll dist[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline void dijkstra(int s) {
	priority_queue< pair<ll , int> , vector< pair<ll , int> > , greater< pair<ll , int> > > q;
	for (int i = 1; i <= n; ++i) 
		dist[i] = INF;
	dist[s] = 0;
	q.push(mp(0 , s));
	while (!q.empty()) {
		int cur = q.top().se; q.pop();
		for (unsigned i = 0; i < a[cur].size(); ++i) {
			int to = a[cur][i].to , w = a[cur][i].w , id = a[cur][i].id;
			if (id == ban) continue;
			if (dist[cur] + (ll)w < dist[to]) {
				dist[to] = dist[cur] + (ll)w;
				q.push(mp(dist[to] , to));
			}
		}
	}
}
inline void sol1() {
	for (int i = 1; i <= n; ++i) {
		ll ans = 0;
		for (unsigned j = 0; j < a[i].size(); ++j) {
			ban = a[i][j].id;
			dijkstra(i);
			chkmax(ans , dist[1]);
		}
		if (ans == INF) printf("%d " , -1);
		else printf("%lld " , ans);
	}	
	printf("\n");
}
inline void modify(int &now , int old , int l , int r , int x , ll w) {
	now = ++size;
	lc[now] = lc[old] , rc[now] = rc[old];
	mx[now] = min(mx[old] , w);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (mid >= x) modify(lc[now] , lc[old] , l , mid , x , w);
	else modify(rc[now] , rc[old] , mid + 1 , r , x , w);
}
inline ll query(int now , int l , int r , int ql , int qr) {
	if (!now)
		return INF;
	if (l == ql && r == qr)
		return mx[now];
	int mid = (l + r) >> 1;
	if (mid >= qr) return query(lc[now] , l , mid , ql , qr);
	else if (mid + 1 <= ql) return query(rc[now] , mid + 1 , r , ql , qr);
	else return min(query(lc[now] , l , mid , ql , mid) , query(rc[now] , mid + 1 , r , mid + 1 , qr));
} 
inline void sol2() {
	set< int > s; s.clear();
	for (int i = 1; i < n; ++i) {
		ll ans = 0 , minv = INF;
		for (unsigned j = 0; j < a[i].size(); ++j) {
			if (a[i][j].to == i + 1) {
				if (a[i][j].w < minv) {
					minv = a[i][j].w;
					dist[i + 1] = dist[i] + (ll)a[i][j].w;
					ban = a[i][j].id;
				}
			}
		}
		s.insert(ban);
	}
	mx[0] = INF;
	for (int i = n; i >= 1; --i) {
		rt[i] = rt[i + 1];
		for (unsigned j = 0; j < a[i].size(); ++j) {
			int v = a[i][j].to , w = a[i][j].w , id = a[i][j].id;
			if (s.find(id) != s.end()) continue;
			modify(rt[i] , rt[i] , 1 , n , v , dist[i] + (ll)w + dist[v]);
		}
	}
	printf("0 ");
	for (int i = 2; i <= n; ++i) {
		ll ans = query(rt[i] , 1 , n , 1 , i - 1);
		if (ans == INF) printf("-1 ");
		else printf("%d " , ans - dist[i]);
	}
	printf("\n");
}

int main() {
	
	#ifndef evenbao
	freopen("rebirth.in" , "r" , stdin);
	freopen("rebirth.out" , "w" , stdout);
	#endif
	
	int caseno;
	read(caseno);
	read(n); read(m);
	for (int i = 1; i <= m; ++i) {
		int u , v , w;
		read(u); read(v); read(w);
		a[u].push_back((edge){v , w , i});
		a[v].push_back((edge){u , w , i});
	}
	if (caseno <= 7) {
		sol1();
		return 0;
	}
	if (12 <= caseno && caseno <= 16) {
		sol2();
		return 0;	
	}
	
	return 0;
}

