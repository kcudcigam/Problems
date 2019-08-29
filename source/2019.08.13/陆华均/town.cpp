#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	T f = 1;
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
int pos, Maxlen, a[300005], b[300005],  anc[300005], h[300005], dfn[300005];
struct info{
	int to, nex;
}l[600005];
inline void dfs(int p, int sum, int fa){
	if (Maxlen < sum) {
		Maxlen = sum;
		pos = p;
	}
	for (int e = h[p]; e; e = l[e].nex) {
		int u = l[e].to;
		if (u != fa) dfs(u, sum + 1, p);
	}
}
int main(){
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	int n, len = 0;
	read(n);
	for (int i = 1; i <= n - 1; i ++) {
		read(a[i]); read(b[i]);
		l[++ len] = (info) {b[i], h[a[i]]};
		h[a[i]] = len;
		l[++ len] = (info) {a[i], h[b[i]]};
		h[b[i]] = len;
		Maxlen = 0;
		dfs(a[i], 0, 0);
		Maxlen = 0;
		dfs(pos, 0, 0);
		write(Maxlen, '\n');
	}
	return 0; 
}

