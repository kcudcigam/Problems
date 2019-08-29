#include<bits/stdc++.h>
#define MAXN 500010

using namespace std;

int n , m;
int son[MAXN] , f[MAXN];
int siz[MAXN] , zz[MAXN];
int ans[MAXN];
int la[MAXN];
int p[MAXN] , d[MAXN];
int s;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void write(T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

inline int zuz(int x) {
	if (zz[x] == x) return x;
	return zz[x] = zuz(zz[x]);
}

inline int las(int x) {
	if (la[x] == x) return x;
	return la[x] = las(la[x]);
}

inline void dfs(int u) {
	s += p[u];
	ans[u] += s;
	s -= d[u];
	if (u != las(u)) dfs(son[u]);
}

int main(){

	freopen("merge.in" , "r" , stdin);
	freopen("merge.out" , "w" , stdout);

	read(n); read(m);
	
	for (int i = 1; i <= n; i++) f[i] = zz[i] = la[i] = i;
	
	while(m--) {
		int opt , x , y;
		read(opt); read(x); read(y);
		if (opt == 1) {
			son[las(y)] = zuz(x);
			f[zuz(x)] = las(y);
			zz[zuz(x)] = zuz(y);
			la[las(y)] = las(x);
		}
		else {
			p[zuz(x)] += y;
			d[las(x)] += y;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (zuz(i) == i) {
			s = 0;
			dfs(i);
		}
	}
	for (int i = 1; i < n; i++) {
		write(ans[i]); putchar(' ');
	}
	write(ans[n]); putchar('\n');

	return 0;
}


