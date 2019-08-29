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

const int N = 1e7 + 10;
int q, n, p, f[N];

int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	for (q = read(); q--;) {
		n = read(), p = read();
		f[1] = 0;
		fox (i, 2, n) {
			f[i] = 1LL * f[i - 1] * i % p;
			if (i & 1) f[i] += 1LL * i * (i - 1) % p;
			else f[i] += 1LL * (i - 2) * (i - 1) % p + i;
			f[i] %= p;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}

