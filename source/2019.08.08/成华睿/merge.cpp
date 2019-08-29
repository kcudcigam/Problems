#include<bits/stdc++.h>
#define rui register unsigned int
#define ll long long
using namespace std;
const int N = 500005;
int f[N], z[N], h[N], a[N];
int n, m, k, x, y, zx, zy;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int find(int son){
	if (f[son] == 0) return son;
	z[son] = (z[son] == 0) ? find(f[son]) : find(z[son]);
	return z[son];
}
void dfs(int son){
	if (h[son] == 1) return;
	if (f[son] == 0){
		h[son] = 1;
		return;
	}
	dfs(f[son]);
	a[son] += a[f[son]];
	h[son] = 1;
	return;
}
int main(){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++){
		read(k);
		read(x);
		read(y);
		if (k == 1){
			zx = find(x);
			zy = find(y);
			if (zx != zy) f[zy] = zx;
		}
		if (k == 2) a[find(x)] += y;
	}
	for (int i = 1; i <= n; i++){
		if (h[i] == 0) dfs(i);
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}


