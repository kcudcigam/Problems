#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

inline int read() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int M = 1e5 + 10, P = 1e9 + 7;
int n, m1, m2, b[11], ans, num, h[M], tot;
struct edge{int nxt, v;} e[M];
struct conn{int x, y;} a1[M], a2[M];
bool a[11], vis[M];

inline void add(int x, int y) {
	e[++tot] = (edge) {h[x], y};
	h[x] = tot;
}

inline void check() {
	++ans;
	fox (i, 1, m1) {
		fox (j, 1 ,m1) {
			if (b[a1[i].x] == a1[j].x && b[a1[i].y] == a1[j].y) break;
			if (b[a1[i].x] == a1[j].y && b[a1[i].y] == a1[j].x) break;
			if (j == m1) return;
		}
	}
	fox (i, 1, m2) {
		fox (j, 1 ,m2) {
			if (b[a2[i].x] == a2[j].x && b[a2[i].y] == a2[j].y) break;
			if (b[a2[i].x] == a2[j].y && b[a2[i].y] == a2[j].x) break;
			if (j == m2) return;
		}
	}
	--ans;
}

void dfs(int x) {
	if (x > n) {check(); return;}
	fox (i, 1, n) {
		if (a[i]) continue;
		a[i] = 1;
		b[x] = i;
		dfs(x + 1);
		a[i] = 0;
	}
}

int sum;
void dfsrd(int x) {
	++sum;
	vis[x] = 1;
	for (int i = h[x]; i; i = e[i].nxt) {
		if (vis[e[i].v]) continue;
		dfsrd(e[i].v);
	}
}

int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	num = read();
	n = read(), m1 = read(), m2 = read();
	fox (i, 1, m1) a1[i].x = read(), a1[i].y = read();
	fox (i, 1, m2) a2[i].x = read(), a2[i].y = read();
	
	if (num <= 6) dfs(1);
	else if (num <= 10) {
		int s1 = 1, s2 = 1;
		fox (i, 1, n) s1 = 1LL * s1 * i % P;
		fox (i, 1, m1 + m2) s2 = 1LL * s2 * 2 % P;
		fox (i, 1, m1) s2 = 1LL * s2 * i % P;
		fox (i, 1, m2) s2 = 1LL * s2 * i % P;
		ans = s1 - s2;
		if (ans < 0) ans += P;
	} else if (num <= 14) {
		int s1 = 1, s2 = 1;
		fox (i, 1, n) s1 = 1LL * s1 * i % P;
		fox (i, 1, m1) {
			add(a1[i].x, a1[i].y);
			add(a1[i].y, a1[i].x);
		}
		fox (i, 1, m2) {
			add(a2[i].x, a2[i].y);
			add(a2[i].y, a2[i].x);
		}
		
		fox (i, 1, n) {
			if (!vis[i]) {
				sum = 0;
				dfsrd(i);
				s2 = 1LL * s2 * sum % P;
			}
		}
		ans = s1 - s2;
		if (ans < 0) ans += P;
	} else ans = num;
	
	cout << ans << endl;
	return 0;
}
