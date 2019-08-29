#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &X) {
	X = 0;
	char C = getchar();
	T F = 1;
	for (; !isdigit(C); C = getchar()) if (C == '-')  F = -1;
	for (; isdigit(C); C = getchar()) X = (X << 1) + (X << 3) + (C ^ 48);
	X *= F;
}
template <typename T> inline void w(T X) {
	if (X > 9) w(X / 10);
	putchar(X % 10 + 48);
}
template <typename T> inline void write(T X, char C) {
	if (X < 0) {
		putchar('-');
		X = -X;
	}
	w(X);
	putchar(C);
}
const int M = 2e5 + 5;
struct info{
	int to, nex;
	long long val;
}l[5 * M];
int len, h[M];
pair <int, int> f[M];
long long dis[M], ans[M], sum[M];
bool vis[M];
priority_queue<pair <long long, int> > q;
inline void add(int x, int y, long long v) {
	l[++ len] = (info) {y, h[x], v};
	h[x] = len;
	l[++ len] = (info) {x, h[y], v};
	h[y] = len;	
}
int main(){
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	int NUM, n, m;
	read(NUM); read(n); read(m);
	for (int i = 1; i <= m; i ++) {
		int x, y;
		long long v;
		read(x); read(y); read(v);
		if (x != y) add(x, y, v);
	}
	for (int i = 2; i <= n; i ++) dis[i] = 1e18;
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		int d = q.top().second;
		q.pop();
		if (!vis[d]) {
			vis[d] = true;
			for (int e = h[d]; e; e = l[e].nex) {
				int u = l[e].to;
				long long v = l[e].val;
				if (dis[u] > dis[d] + v) {
					dis[u] = dis[d] + v;
					f[u].first = d;
					f[u].second = v;
					q.push(make_pair(-dis[u], u));
				}
			}
		} 
	}
	for (int i = 2; i <= n; i ++) sum[i] = 1e18;
	for (int i = 2; i <= n; i ++) {
		int x = f[i].first, y = i;
		long long z = f[i].second;
		for (int i = 2; i <= n; i ++) dis[i] = 1e18;
		memset(vis, false, sizeof(vis));
		q.push(make_pair(0, 1));
		while(!q.empty()) {
			int d = q.top().second;
			q.pop();
			if (!vis[d]) {
				vis[d] = true;
				for (int e = h[d]; e; e = l[e].nex) {
					int u = l[e].to;
					long long v = l[e].val;
					if (((d == x && u == y) || (d == y && u == x)) && v == z )continue;
					if (dis[u] > dis[d] + v) {
						dis[u] = dis[d] + v;
						q.push(make_pair(-dis[u], u));
					}
				}
			} 
		}		
		sum[x] = min(sum[x], dis[x]);
		sum[y] = min(sum[y], dis[y]);
	}
	for (int i = 1; i < n; i ++) {
		if (sum[i] == 1e18) {
			printf("-1 ");
		}
		else write(sum[i], ' ');
	}
	if (sum[n] == 1e18) {
		printf("-1\n");
	}
	else write(sum[n], '\n');
	return 0;
}


