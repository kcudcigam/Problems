#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	int to, nxt;
} edge[600010];
int n, m, q, head[300010], tot, sum[300010], du[300010];
void add(int from, int to) {
	edge[++tot].nxt = head[from];
	edge[tot].to = to;
	head[from] = tot;
}
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()); if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
inline ll RD() {
	ll x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int main() {
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	n = rd(); m = rd(); q = rd();
	for (int i = 1; i <= m; i++) {
		int x = rd(), y = rd();
		add(x, y); add(y, x);
		du[x]++; du[y]++;
	}
	if (n <= 3000 && m <= 3000 && q <= 3000) {
		for (int i = 1; i <= q; i++) {
			int type = rd();
			if (type == 1) {
				int x = rd(), y = rd();
				sum[x] += y;
				for (int i = head[x]; i; i = edge[i].nxt) sum[edge[i].to] += y;
			} else {
				int x = rd();
				printf("%d\n", sum[x]);
			}
		}
	} else {
		bool flag = 1;
		for (int i = 2; i <= n; i++) {
			if (du[i] > 10) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int i = 1; i <= q; i++) {
				int type = rd();
				if (type == 1) {
					int x = rd(), y = rd();
					sum[x] += y;
					for (int i = head[x]; i; i = edge[i].nxt) sum[edge[i].to] += y;
				} else {
					int x = rd();
					printf("%d\n", sum[x]);
				}
			}
		} else {
			for (int i = 1; i <= q; i++) {
				int type = rd();
				if (type == 1) {
					int x = rd(), y = rd();
					if (du[x] == 1) {
						sum[edge[head[x]].to] += y;
					} else {
						sum[x] += y;
					}
				} else {
					int x = rd();
					if (du[x] == 1) {
						printf("%d\n", sum[edge[head[x]].to]);
					} else {
						printf("%d\n", sum[x]);
					}
				}
			}
		}
	}
	return 0;
}

