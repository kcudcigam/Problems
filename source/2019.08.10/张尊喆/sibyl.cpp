#include<iostream>
#include<cstring>
#include<cstring>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
const int N = 300005;
ll w[N<<1], ad[N], s[N];
int h[N], to[N<<1], ne[N<<1];
int tot = -1, n, m, q;
inline void add(int x,int y) {
	ne[++tot] = h[x];
	h[x] = tot, to[tot] = y;
}

int read(void) {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}
int d[N];
vector<int> bi[N];
int main() {
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout); 
	memset(h, -1, sizeof(h));
	n = read(), m = read(), q = read();
	for (int i = 1;i <= m; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
		d[x]++, d[y]++;
	}
	int D = sqrt(m);
	for (int i = 1;i <= n; i++) {
		if (d[i] >= D) {
			for (int j = h[i]; ~j; j = ne[j]) {
				bi[to[j]].push_back(j^1);
			}
		}
	}
	for (int i = 1;i <= q; i++) {
		int op = read(), a = read();
		if (op) {
			int b = read();
			ad[a] += b;
			s[a] += b;
			for (int j = 0;j < bi[a].size(); j++) {
				s[to[bi[a][j]]] += b;
			}
		}
		else {
			if (d[a] >= D)
				printf ("%lld\n", s[a]);
			else {
				for (int j = h[a]; ~j; j = ne[j]) {
					s[a] += ad[to[j]] - w[j];
					w[j] = ad[to[j]];
				}
				printf ("%lld\n", s[a]);
			}
		}
	}
	return 0;
}
