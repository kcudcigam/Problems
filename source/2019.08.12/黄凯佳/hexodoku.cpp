#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do x=x*10+c-48; while (isdigit(c=getchar()));
	return x*f;
}
const int a[35]={0, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7};
const int b[35]={0, 5, 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7};
const int c[35]={0, 2, 3, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 5, 6};
const int d[10][35]={
{0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1},
};

int sta[10], stb[10], stc[10], ste[10];
int m, n, v[35], cnt, flag=0;

void dfs(int x) {
	if (x==32) {
		++cnt;
		if (cnt==n) {
			flag=1;
			printf("Found\n");
			for (reg int i=1; i<=31; ++i) printf("%d ", v[i]);
		}
		return;
	}
	if (v[x]) {
		dfs(x+1);
		if (flag) return;
	}
	else {
		int state=sta[a[x]]|sta[b[x]]|stc[c[x]];
		for (reg int k=0; k<7; ++k) if (d[k][x]) state|=ste[k];
		for (reg int i=1; i<=m; ++i) {
			if (state & (1<<i-1)) continue;
			v[x]=i;
			int marka=sta[a[x]], markb=stb[b[x]], markc=stc[c[x]];
			int markd[10];
			for (reg int k=0; k<7; ++k) markd[k]=ste[k];
			sta[a[x]]|=1<<v[x]-1; stb[b[x]]|=1<<v[x]-1; stc[c[x]]|=1<<v[x]-1;
			for (reg int k=0; k<7; ++k) if (d[k][i]) ste[k]|=1<<v[x]-1;
			dfs(x+1);
			if (flag) return;
			v[x]=0;
			sta[a[x]]=marka; stb[b[x]]=markb; stc[c[x]]=markc;
			for (reg int k=0; k<7; ++k) ste[k]=markd[k];
		}
	}
}

int main() {
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	m=read(); n=read();
	/*
	if (m>7 && n!=1) {
		printf("No way\n");
		return 0;
	}
	for (reg int i=1, j; i<=n; ++i) {
		v[i]=read();
		if (!v[i]) continue;
		sta[a[i]]|=1<<v[i]-1; stb[b[i]]|=1<<v[i]-1; stc[c[i]]|=1<<v[i]-1;
		for (reg int k=0; k<7; ++k) if (d[k][i]) ste[k]|=1<<v[i]-1;
	}
	dfs(1);*/
	if (!flag) printf("No way\n");
	return 0;
}

