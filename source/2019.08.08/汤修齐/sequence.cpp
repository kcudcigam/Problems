#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 5e5 + 10;

template <typename T> void read(T &x){
	int f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}

int n, m;
LL f[maxn], c[maxn];

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m);
	LL cnt = 0;
	for (int i = 1; i <= m; i++){
		int l, r, s, e;
		read(l); read(r); read(s); read(e);
		f[l] += s;
		c[l + 1] += (e - s) / (r - l);
		f[r + 1] -= e;
		c[r + 1] -= (e - s) / (r - l);
	}
	LL ans = 0, t = 0, k = 0;
	for (int i = 1; i <= n; i++){
		t += f[i];
		k += c[i];
		t += k;
		ans ^= t;
	}
	printf("%lld\n", ans);
	return 0;
}
