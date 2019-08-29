#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

const int MAXN = 50001;

int n, m;
long long a[MAXN], t[MAXN * 4];

void gt(int o, int l, int r, int pos, long long s) {
	t[o] ^= s;
	if(l == r) return;
	int mid = (l + r) >> 1;
	int lc = o << 1;
	int rc = (o << 1) + 1;
	if(pos <= mid) gt(lc, l, mid, pos, s);
	else gt(rc, mid + 1, r, pos, s);
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n);
	read(m);
	for(register int q = 1; q <= m; ++q) {
		int l, r;
		long long s, e, b, c;
		read(l);
		read(r);
		read(s);
		read(e);
		b = (e - s) / ((long long)(r - l));
		c = s;
		for(register int i = l; i <= r; ++i) {
			gt(1, 1, n, i, a[i] ^ (a[i] + c));
			a[i] += c;
			c += b;
		}
	}
	printf("%lld", t[1]);
	return 0;
}
