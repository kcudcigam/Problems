#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 500010;
int n, m;
long long a[MAXN], b[MAXN];

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= m; ++i) {
		long long l, r, s, e; 
		read(l); read(r); read(s); read(e);
		long long x;
		if (l == r) x = 0;
		else x = (e - s)/(r - l);
		a[l + 1] += x; a[r + 1] -= x;
		b[l] += s; b[r + 1] -= s;
	}
	for (int i = 2; i <= n; ++i) a[i] += a[i - 1];
	for (int i = 2; i <= n; ++i) b[i] += b[i - 1] + a[i];
	
	long long ans = b[1];
	for (int i = 2; i <= n; ++i) ans ^= b[i];
	
	cout << ans << endl;

	return 0;
}



