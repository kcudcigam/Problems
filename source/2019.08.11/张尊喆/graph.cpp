#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 300005;
int h[N], to[N<<1], w[N<<1];
int ne[N<<1], tot, n, m, ask;
int maxw;
void read(int &x) {
	x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
}

inline void add(int x,int y,int z) {
	ne[++tot] = h[x], h[x] = tot;
	to[tot] = y, w[tot] = z;
}

int v[N];
queue<int> q;

bool check(int mid, int x, int t) {
	memset(v, 0, sizeof(v));
	v[x] = 1;
	while (q.size()) q.pop();
	q.push(x);
	while (!q.empty()) {
		int tmp = q.front(); q.pop();
		for (int i = h[tmp]; i; i = ne[i]) {
			int y = to[i];
			if (v[y] || w[i] > mid) continue;
			if (y == t) return true;
			v[y] = 1;
			q.push(y);
		}
	}
	return false;
}


int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout); 
	read(n), read(m), read(ask);
	 for (int i = 1;i <= m; i++) {
	 	int x, y, z;
	 	read(x), read(y), read(z);
	 	add(x, y, z);
	 	add(y, x, z);
	 	maxw = max(maxw, z);
	 }
	 for (int i = 1;i <= ask; i++) {
	 	int x, y;
	 	read(x), read(y);
	 	int l = 1, r = maxw;
	 	while (l <= r) {
	 		int mid = (l + r) >> 1;
	 		if (check(mid, x, y)) r = mid - 1;
	 		else l = mid + 1;
	 	}
	 	if (l > maxw) printf ("-1\n");
	 	else printf ("%d\n", l);
	 }
	 return 0;
}
	 
	 
	 
	 
