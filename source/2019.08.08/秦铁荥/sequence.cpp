#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

inline int read() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 5e5 + 10;
int n, m;
ll f[N], g[N];

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), m = read();
	int l, r; ll s, e, gc, ans;
	fox (i, 1, m) {
		l = read(), r = read(), s = read(), e = read();
		gc = (e - s) / max(r - l, 1);
		f[l] += s, f[r + 1] -= e;
		g[l] += gc, g[r] -= gc;
	}
	
	s = gc = ans = 0;
	fox (i, 1, n) {
		s += f[i] + gc, gc += g[i];
		ans = ans ^ s;
	}
	
	printf("%lld\n", ans);
	return 0;
}

