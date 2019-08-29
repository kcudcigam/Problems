#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 2e5 + 10, LOG = 20;

struct node {
	LL val, c; int p;
	
	node (LL val = 0, LL c = 0, int p = 0) : val(val), c(c), p(p) {
		
	}
	
	bool operator < (const node &t) const {
		return val + c < t.val + t.c;
	}
};

priority_queue<node> q;

int n, A, B, C, D;
int a[maxn];
LL d[maxn], f[maxn];
int fa[maxn][LOG], Min[maxn][LOG];

inline LL calc(int x){
	return ((1ll * A * x + B) * x + C) * x + D;
}

inline int query(int l, int r){
	int re = l;
	for (int i = LOG - 1; i >= 0; i--)
		if (fa[r][i] >= l){
			if (a[Min[r][i]] < a[re]) re = Min[r][i];
			r = fa[r][i];
		}
	return a[re] < a[Min[l][0]] ? re : Min[l][0];
}

int main(){
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		d[i] = calc(a[i]);
	}
	for (int i = 1; i <= n; i++){
		fa[i][0] = i - 1; Min[i][0] = i;
		for (int j = 1; j < LOG; j++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
			if (a[Min[fa[i][j - 1]][j - 1]] < a[Min[i][j - 1]])
				Min[i][j] = Min[fa[i][j - 1]][j - 1];
			else Min[i][j] = Min[i][j - 1];
		}
	}
	memset(f, 0x80, sizeof f);
	a[0] = INT_MAX;
	f[0] = 0; q.push(node(0, 0, 0));
	for (int i = 1; i <= n; i++){
		node top;
		q.push(node(f[i - 1], d[i], i));
		do {
			top = q.top();
			int t = query(max(1, top.p), i);
			if (a[top.p] >= a[t] && top.p != t){
				q.pop();
				q.push(node(top.val, d[t], t));
			} else break;
		} while (q.size());
		f[i] = top.val + top.c;
	}
	printf("%lld\n", f[n]);
	return 0;
}
