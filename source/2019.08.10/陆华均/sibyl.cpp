#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f= -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	w(x);
	putchar(c);
}
struct info{
	int to, nex;
}l[600005], g[600005];
int len, head[300005], tail[300005], f[300005], sum[300005], tag[300005];
bool vis[300005];
queue <int> qq;
int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	int n, m, q;
	read(n); read(m); read(q);
	for (int i = 1; i <= m; i ++) {
		int x, y;
		read(x); read(y);
		l[++ len] = (info) {y, head[x]};
		head[x] = len;
		l[++ len] = (info) {x, head[y]};
		head[y] = len;
	}
	if (n <= 3000) {
		for (int i = 1; i <= q; i ++) {
			int opt, x;
			read(opt); read(x);
			if (opt == 1) {
				int y;
				read(y);
				sum[x] += y;
				for (int e = head[x]; e; e = l[e].nex) {
					int u = l[e].to;
					if (!vis[u]) {
						vis[u] = true;
						sum[u] += y;
					}
				}
				for (int e = head[x]; e; e = l[e].nex) {
					vis[l[e].to] = false;
				}
			}
			else {
				write(sum[x], '\n');
			}
		}
	}
	else {
		len = 0;
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) continue;
			vis[i] = true;
			qq.push(i);
			while(!qq.empty()) {
				int d = qq.front();
				qq.pop();
				for (int e = head[d]; e; e = l[e].nex) {
					int u = l[e].to;
					if (!vis[u]) {
						qq.push(u);
						vis[u] = true;
						f[u] = d;
					}
					else if (f[u] != d && f[d] != u) {
						g[++ len] = (info) {u, tail[d]};
						tail[d] = len;
					}
				}
			}
		}
		for (int i = 1; i <= q; i ++) {
			int opt, x;
			read(opt); read(x);
			if (opt == 1) {
				int y;
				read(y);
				sum[f[x]] += y;
				sum[x] += y; 
				tag[x] += y;
				for (int e = tail[i]; e; e = g[e].nex) {
					int u = g[e].to;
					sum[u] += y;
				}
			}
			else {
				write(sum[x] + tag[f[x]], '\n');
			}
		}
	}
	return 0;
}



