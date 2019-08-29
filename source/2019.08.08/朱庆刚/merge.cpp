#include<cstdio>
using namespace std;

const int MAXN = 500001;

int n, q;
int fa[MAXN], s[MAXN];

int fn(int x) {
	return fa[x] == x ? x : fn(fa[x]);
}
int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= q; ++i)
		s[i] = i;
	for(int i = 1; i <= q; ++i) {
		int o, x, y;
		scanf("%d %d %d", &o, &x, &y);
		if(o == 1) {
			int fnxr = fn(x);
			int fnyr = fn(y);
			if(fnxr == fnyr) continue;
			fa[fnxr] = fnyr;
		} else {
			s[fn(x)] += y;
		}
	}
	for(int i = 1; i <= n; ++i) {
		int now = i, res = s[i];
		for(;fa[now] != now;) {
			now = fa[now];
			res += s[now];
		}
		printf("%d ", res);
	}
	return 0;
}


