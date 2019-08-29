#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int P = 1e9 + 7, N = 30010;
int n, X, f[N], g[N], ans, sumf[N], sumg[N];
struct money {int a, b, c;} a[N];

inline int up(int x) {return x < P ? x : x - P;}
inline void add(int&x, int y) {
	x += y;
	if (x >= P) x-= P;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n = rd(), X = rd();
	for (int i = n; i; --i) a[i].a = rd(), a[i].b = rd(), a[i].c = rd();
	
	f[0] = g[0] = 1;
	int bf, cg;
	fox (i, 1, n) {
		fox (j, 0, X) {
			sumf[j] = f[j], sumg[j] = g[j];
			if (j - a[i].a > -1) add(sumf[j], sumf[j - a[i].a]), add(sumg[j], sumg[j - a[i].a]);
		}
		bf = a[i].a * a[i].b, cg = a[i].a * a[i].c;
		fox (j, 0, X - 1) {
			if (j < bf) add(f[j + a[i].a], sumf[j]);
			else add(f[j + a[i].a], up(sumf[j] - sumf[j - bf]));
			
			if (j < cg) add(g[j + a[i].a], sumg[j]);
			else add(g[j + a[i].a], up(sumg[j] - sumg[j - cg]));
		}
	}
	
	fox (i, 0, 20000) add(ans, 1LL * g[i] * f[i + X] % P);
	printf("%d\n", ans);
	return 0;
}

