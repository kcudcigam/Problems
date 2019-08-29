#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define Set(a,b) memset(a, b, sizeof a)
#define Cpy(a,b) memcpy(a, b, sizeof b)
#define ll long long
using namespace std;

inline int read() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
inline void chkmax(int &x, int y) {if (x < y) x = y;}
inline void chkmin(int &x, int y) {if (x > y) x = y;}

const int N = 1e5 + 10;
int n, a[N];
ll f[N], g[N], ans;

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	n = read();
	fox (i, 1, n) a[i] = read();
	
	ll s = f[1] = a[1];
	fox (i, 2, n) {
		if (s > 0) s = s + a[i];
		else s = a[i];
		f[i] = max(s, f[i - 1]);
	}
	
	s = g[n] = a[n];
	for (int i = n - 1; i; --i) {
		if (s > 0) s = s + a[i];
		else s = a[i];
		g[i] = max(s, g[i + 1]);
	}
	
	fox (i, 1, n - 1) ans = max(f[i] + g[i + 1], ans);
	
	printf("%lld\n", ans);
	return 0;
}
