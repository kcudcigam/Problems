#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

inline int read() 
{
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 100100;
int n, q, f[N], fa[N], ans[N], cnt;
bool vis[N];

int find1(int x)
{
	if(f[x] == x) return x;
	else return f[x] = find1(f[x]); 
}

int tx, ty;
inline void merge(int x, int y) 
{
	tx = find1(x), ty = find1(y);
	if (tx == ty) return;
	fa[tx] = f[tx] = fa[ty] = f[ty] = ++cnt;
	f[cnt] = cnt;
}

void get1(int x) 
{
	if (vis[x] == 1) return;
	if (fa[x]!=0) get1(fa[x]);
	ans[x] += ans[fa[x]];
	vis[x] = 1;
}

int main() 
{
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	cnt = n = read(), q = read();
	fir (i, 1, n) f[i] = i;
	int cz, x, y;
	fir (i, 1, q) 
	{
		cz = read(), x = read(), y = read();
		if (cz == 1) merge(x, y);
		else ans[find1(x)] += y;
	}
	
	fir (i, 1, n) get1(i);
	
	fir (i, 1, n-1) 
	{
		cout<<ans[i]<<' ';
	}
	cout<<ans[n]<<endl;
	return 0;
}

