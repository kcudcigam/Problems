#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int rd(){
	int re=0; bool f=1; char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f = 0; c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return f ? re : -re;
}

const int N = 3e5 + 10, M = 6e5 + 10, D = 400;
int n, m, q, h[N], v[N], ans[N], tot, d[N];
struct ddd{int x, y;} a[M];
struct edge{int nxt, v;} e[M];

inline void add(int x, int y) {
	e[++tot] = (edge) {h[x], y};
	h[x] = tot;
}

inline int val(int x) {
	if (d[x] >= D) return ans[x];
	else {
		int s = ans[x];
		for (int i = h[x]; i; i = e[i].nxt) s += v[e[i].v];
		return s;
	}
}

inline void addd(int x, int y) {
	v[x] +=y, ans[x] += y;
	for (int i = h[x]; i; i = e[i].nxt) {
		if (d[e[i].v] < D) continue;
		ans[e[i].v] += y;
	}
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n = rd(), m = rd(), q = rd();
	fox (i, 1, m) {
		a[i].x = rd(), a[i].y = rd();
		++d[a[i].x], ++d[a[i].y];
	}
	
	fox (i, 1, m) {
		if (d[a[i].x] >= D || d[a[i].y] < D) add(a[i].y, a[i].x);
		if (d[a[i].y] >= D || d[a[i].x] < D) add(a[i].x, a[i].y);
	}
	
	int x, y, tp;
	fox (i, 1, q) {
		tp = rd();
		if (tp == 0) printf("%d\n", val(rd()));
		else {x = rd(), y = rd(); addd(x, y);}
	}
	return 0;
}
