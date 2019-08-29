#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define LD long double
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {
		if(c == '-') f = -f;
	}
	for(; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {write(x); putchar(sp);}
const int maxn = 300030, maxm = 300030;
int n, m, q, sub2 = 1, sub3 = 1, tot = 0, head[maxn], val[maxn], deg[maxn], flg[3030];
struct Edge {
	int from, to, nxt;
} edge[maxm << 1];
void add_edge(int u, int v) {
	edge[++tot].from = u; edge[tot].to = v; edge[tot].nxt = head[u]; head[u] = tot;
}
int main() {
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	read(n); read(m); read(q);
	_rep(i, 1, m) {
		int x, y; read(x); read(y);
		add_edge(x, y); add_edge(y, x);
		deg[x]++; deg[y]++;
		sub3 = (sub3 & (x == 1 || deg[x] < 10) & (y == 1 || deg[y] < 10));
	}
	if(n >= 3000 && n <= 3000 && m <= 3000 && q <= 3000) {
		_rep(i, 1, q) {
			memset(flg, 0, sizeof(flg));
			int opt, x, y; read(opt); read(x);
			if(opt == 0) {
				writesp(val[x]);
			} else {
				read(y); val[x] += y; flg[x] = 1;
				for(int i = head[x]; i; i = edge[i].nxt) {
					val[edge[i].to] += y * (1 - flg[edge[i].to]);
					flg[edge[i].to] = 1;
				}
			}
		}
	} else if(sub3) {
		int val1 = 0;
		_rep(i, 1, q) {
			int opt, x, y; read(opt); read(x);
			if(opt == 0) {
				int ans = val[x];
				if(x != 1) {
					for(int i = head[x]; i; i = edge[i].nxt) {
						if(edge[i].to == 1) {
							ans += val1; break;
						}
					}
				} else {
					ans += val1;
				}
				writesp(ans);
			} else {
				read(y); 
				if(x != 1) {
					val[x] += y;
					for(int i = head[x]; i; i = edge[i].nxt) {
						val[edge[i].to] += y;
					}	
				} else {
					val1 += y;
				}
			}
		}
	} else {
		cout << "BYF AK IOI\n";
	}
	return 0;
}

