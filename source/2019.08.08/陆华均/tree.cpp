#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	register T f = 1;
	register char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	w(x);
	putchar(c);
}
int T, n, k, c[50005], d[50005], f[50005], dth[50005], depth;
vector <int> v[50001], son[50001], det[50001];
inline void build(int p, int dep) {
	dth[p] = dep;
	det[dep].push_back(p);
	depth = max(depth, dep);
	for (int i = 0; i < v[p].size(); i ++) {
		if (!dth[v[p][i]]) {
			f[v[p][i]] = p;
			son[p].push_back(v[p][i]);
			build(v[p][i], dep + 1);
		}
	}
}
inline void modify(int p) {
	int m = k;
	while(m --) {
		c[p] ^= 1;
		p = f[p];
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(T);
	while(T --) {
		for (int i = 1; i <= n; i ++) {
			v[i].clear();
			son[i].clear();
			det[i].clear();
			dth[i] = 0;
		}
		depth = 0;
		read(n); read(k);
		for (int i = 1; i <= n - 1; i ++) {
			int x, y;
			read(x); read(y);
			v[x].push_back(y); 
			v[y].push_back(x);
		}
		build(1, 1);
		for (int i = 1; i <= n; i ++) read(c[i]);
		for (int i = 1; i <= n; i ++) read(d[i]);
		bool flg = false;
		for (int i = depth; i >= 1; i --) {
			for (int j = 0; j < det[i].size(); j ++) {
				int u = det[i][j];
				if (c[u] != d[u]) {
					if (i < k) flg = true;
					else modify(u);
				}
				if (flg) break;
			}
			if (flg) break;
		}
		if (flg) printf("No\n");
		else printf("Yes\n");
	} 
	return 0;
}


