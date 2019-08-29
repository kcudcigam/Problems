#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 300010;
int n, rt, mx, d1, d2, a[MAXN], b[MAXN], p[MAXN], fa[MAXN], fir[MAXN], sec[MAXN], ans[MAXN];
vector<int>v[MAXN];

void dfs1(int x) {
	for (int i = 0; i < v[x].size(); ++i) {
		int y = v[x][i];
		if (y == fa[x]) continue;
		fa[y] = x;
		dfs1(y);
	}
}
/*
void dfs2(int x, int fax, int dep){
	if (dep > mx) {mx = dep; rt = x;}
	for (int i = 0; i < v[x].size(); ++i) {
		int y = v[x][i];
		if (y == fax) continue;
		dfs2(y, x, dep + 1);
	}
}

void dfs3(int x) {
	p[x] = 1;
	if (x == 1) return;
	d1++; dfs3(fa[x]);
}

int dfs4(int x) {
	if (p[x]) return x;
	d2++; return dfs4(fa[x]); 
}

int dfs5(int x, int dep) {
	if (dep == 0) return x;
	return dfs5(fa[x], dep - 1);
}*/

int fnd(int x) {
	if (p[x] != x) p[x] = fnd(p[x]);
	return p[x];
}

void AddEdge(int x, int y) {
	v[x].push_back(y);
}

void updte(int x, int en) {
//	cerr << "x en fir sec" <<x<<" " << en<<" "<<fir[x]<<" "<<sec[x]<< endl;
	if (x == en) return;
	if (fir[x] + 1 > fir[fa[x]]) {sec[fa[x]] = fir[fa[x]]; fir[fa[x]] = fir[x] + 1;}
	else sec[fa[x]] = max(sec[fa[x]], fir[x] + 1);
	ans[en] = max(ans[en], fir[fa[x]] + sec[fa[x]]);
	updte(fa[x], en);
}

int main(){
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	read(n);
	for (int i = 1; i < n; ++i) {
		read(a[i]); read(b[i]);
		AddEdge(a[i], b[i]); AddEdge(b[i], a[i]);
	}
	
/*	rt = 1; mx = 0;
	dfs2(1, 0, 0);
	int st = rt; rt = 1; mx = 0;
	dfs2(st, 0, 0);
	
	dfs1(1);
	
	dfs3(st);
	int lsr = dfs4(rt), rrrt;
	if (d1 > d2) rrrt = dfs5(st, (d1 + d2) / 2); 
	else rrrt = dfs5(rt, (d1 + d2) / 2);
	
	for (int i = 1; i <= n; ++i) fa[i] = 0;
	dfs1(rrrt);*/
	
	dfs1(1);
	
	for (int i = 1; i <= n; ++i) p[i] = i;
	for (int i = 1; i < n; ++i) {
		if (fa[a[i]] == b[i]) swap(a[i], b[i]);
		int fai = fnd(a[i]), fbi = fnd(b[i]);
		p[fbi] = fai;
		updte(b[i], fai);
		cout << ans[fai] << endl;
	}

	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/
