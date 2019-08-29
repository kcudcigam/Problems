#include<bits/stdc++.h>
#define MAXN 200010
#define MAXLOG 20

using namespace std;

int T;
int n , k;
int siz[MAXN] , a[MAXN] , d[MAXN];
int f[MAXN][MAXLOG];
int dep[MAXN];

struct node{
	int nxt , t;
} edge[MAXN << 1];
int head[MAXN] , cnt;

int del[MAXN] , pcf;

bool h;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

inline void addedge(int u , int v) {
	edge[++cnt].nxt = head[u];
	edge[cnt].t = v;
	head[u] = cnt;
}

void dfs(int u , int fa) {
	siz[u] = 1; f[u][0] = fa; dep[u] = dep[fa] + 1;
	for (int i = 1; i < MAXLOG; i++) {
		f[u][i] = f[f[u][i - 1]][i - 1];
	}
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].t;
		if (v == fa) continue;
		dfs(v , u);
		siz[u] += siz[v];
	}
}

int byf(int u , int wzy) {
	for (int i = MAXLOG - 1; i; i--) {
		if ((1 << i) <= wzy) {
			wzy -= (1 << i);
			u = f[u][i];
		} 
	}
	return u;
}

void dfs2(int u) {
	if (h) return;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].t;
		if (v == f[u][0]) continue;
		dfs2(v);
	}
	pcf += del[u];
	del[u] = 0;
	if (pcf & 1) a[u] = a[u] ? 0 : 1;
	if (a[u] != d[u]) {
		if (dep[u] < k) {
			h = 1;
			return;
		}
		del[byf(u , k)]++;
		a[u] = d[u];
		pcf++;
	}
}

int main(){

	freopen("tree.in" , "r" , stdin);
	freopen("tree.out" , "w" ,stdout);

	read(T);
	
	while(T--) {
		h = 0;
		read(n); read(k);
		memset(head , 0 , sizeof(head));
		cnt = 0;
		memset(f , 0 , sizeof(f));
		for (int i = 1; i < n; i++) {
			int x , y; 
			read(x); read(y);
			addedge(x , y);
			addedge(y , x);
		}
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= n; i++) read(d[i]);
		
		dfs(1 , 0);
		pcf = 0;
		dfs2(1);
		if (h) {
			cout << "No" << endl;
		}
		else cout << "Yes" << endl;
	}

	return 0;
}


