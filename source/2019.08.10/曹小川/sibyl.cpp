#include<bits/stdc++.h>
#define N 300010
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (!f) c = -c;
}
int cnt, n, m, Q;
int head[N], w[N];
struct edge{
	int v, nxt; 
}e[N << 1];
inline void aedge(int u, int v){
	++cnt;
	e[cnt].nxt = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);	
	read(n), read(m), read(Q);
	for (int i = 1; i <= m; ++i){
		int x, y;
		read(x), read(y);
		aedge(x, y);
		aedge(y, x);
	}
	while (Q--){
		int opt, x, y;
		read(opt);
		if (opt == 1){
			read(x), read(y);
			w[x] += y;
			for (int i = head[x]; i; i = e[i].nxt)
				w[e[i].v] += y;
		}
		else{
			read(x);
			printf("%d\n", w[x]);
		}
	}
	return 0;
}
