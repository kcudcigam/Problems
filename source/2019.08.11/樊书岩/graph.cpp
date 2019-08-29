#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define ULL unsigned long long
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
const int maxm = 300030, maxn = 300030;
int n, m, q, tot = 0, x, y;
struct Edge {
	int from, to, val, nxt;
} edge[maxm << 1];
int head[maxn];
void add_edge(int u, int v, int w) {
	edge[++tot].from = u; edge[tot].to = v; edge[tot].val = w; edge[tot].nxt = head[u]; head[u] = tot;
}
int dp[1010][1010];
const int INF = INT_MAX / 2;
bool use[1010] = {0};
void give_up() {
	while(1) {puts("I AK IOI");}
}
struct node {
	int id, val;
};
void search(int top) {
	memset(use, 0, sizeof(use));
	std::queue<node> q;
	q.push((node){top, 0});
	dp[top][top] = 0; use[top] = 1;
	while(!q.empty()) {
		node u = q.front(); q.pop();
		int val = u.val;
		for(int i = head[u.id]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if(v == top) continue;
		//	if(dp[top][v] < std::max(val, edge[i].nxt)) continue;
			dp[top][v] = std::min(dp[top][v], std::max(val, edge[i].val));
			if(use[v] == 1) continue;
			q.push((node){v, dp[top][v]});
			use[v] = 1;
		//	std::cout << v << " " << dp[top][v] << "\n";
		}
	}
	
}
int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	read(n); read(m); read(q);
	_rep(i, 1, m) {
		int u, v, w;
		read(u); read(v); read(w);
		add_edge(u, v, w); add_edge(v, u, w);
	}
	if(n <= 1000 && m <= 1000) {
		_rep(i, 1, n) {
			_rep(j, 1, n) {
				dp[i][j] = INF;
			}
		}
		_rep(i, 1, n) {
			search(i);
		}
//		_rep(i, 1, n) {
//			_rep(j, 1, n) {
//				std::cout << dp[i][j] << " ";
//			}
//			std::cout << std::endl;
//		}
		_rep(i, 1, q) {
			int x, y;
			read(x); read(y);
			writesp(dp[x][y] == INF ? -1 : dp[x][y]);
		}
	} else {
		give_up();
	}
	return 0;
}

