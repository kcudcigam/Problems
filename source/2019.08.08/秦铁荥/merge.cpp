#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define Set(a,b) memset(a, b, sizeof a)
#define Cpy(a,b) memcpy(a, b, sizeof b)
#define ll long long
using namespace std;

inline int read() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void chkmax(int &x, int y) {if (x < y) x = y;}
inline void chkmin(int &x, int y) {if (x > y) x = y;}

const int N = 1e6 + 10;
int n, q, f[N], fa[N], jz[N], cnt;
bool vis[N];

int _find(int x) {
	return f[x] == x ? x : f[x] = _find(f[x]);
}

int fx, fy;
inline void Merge(int x, int y) {
	fx = _find(x), fy = _find(y);
	if (fx == fy) return;
	fa[fx] = f[fx] = fa[fy] = f[fy] = ++cnt;
	f[cnt] = cnt;
}

void getit(int x) {
	if (vis[x]) return;
	if (fa[x]) getit(fa[x]);
	jz[x] += jz[fa[x]];
	vis[x] = 1;
}

int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	cnt = n = read(), q = read();
	fox (i, 1, n) f[i] = i;
	int opt, x, y;
	fox (i, 1, q) {
		opt = read(), x = read(), y = read();
		if (opt == 1) Merge(x, y);
		else jz[_find(x)] += y;
	}
	
	fox (i, 1, n) getit(i);
	
	fox (i, 1, n) printf("%d%c", jz[i], (i == n ? '\n' : ' '));
	return 0;
}

