#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}
const int N = 500005;
struct node{
	ll sum;
	int fa;
}fak[N];
int f[N], tot, e[N];
int get(int x) {
	if (fak[x].fa) return get(fak[x].fa);
	return x;
}
int main() {
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	ll n, q;
	read(n), read(q);
	for (int i = 1;i <= q; i++) {
		int x = 0;
		ll a, b;
		read(x), read(a), read(b);
		if (x == 1) {
			if (!f[a] && !f[b]) {
				e[a] = e[b] = f[b] = f[a] = ++tot;
			}
			else if (!f[a]) {
				if (fak[f[b]].sum == 0)
					e[a] = f[a] = f[b];
				else
					e[a] = f[a] = f[b] = fak[f[b]].fa = ++tot;
			}
			else if (!f[b]) {
				if (fak[f[a]].sum == 0) e[b] = f[b] = f[a];
				else e[b] = f[b] = f[a] = fak[f[a]].fa = ++tot;
			}
			else {
				if (fak[f[a]].sum == 0) f[b] = fak[f[b]].fa = f[a];
				else if (fak[f[b]].sum == 0) f[a] = fak[f[a]].fa = f[b];
				else f[a] = f[b] = fak[f[a]].fa = fak[f[b]].fa = ++tot;
			}
		}
		else {
			if (!f[a])
				e[a] = f[a] = ++tot;
			f[a] = get(f[a]);
			fak[f[a]].sum += b;
		}
	}
	for (int i = 1;i <= n; i++) {
		ll k = e[i], ans = 0;
		do {
			ans += fak[k].sum;
			k = fak[k].fa;
		}while(k);
		printf("%lld ", ans);
	}
	return 0;
}
/*
5 9
1 3 5
2 3 2
2 1 3
1 2 4
2 4 1
2 1 6
1 1 3
2 1 3
1 1 4


*/
