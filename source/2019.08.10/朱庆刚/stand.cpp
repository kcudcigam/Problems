#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
int n, m, a[6];
set<int>h[55];
set<int>chn;

long long f(long long x) {
	long long res = 0LL;
	for(int i = 1; i <= 5; ++i) {
		res += a[i] * pow(x, (long long)i);
	}
	return res;
}

int main() {
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= 5; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		for(int j = l; j <= r; ++j)
			h[j].insert(i);
	}
	long long ans = 0;
	
	for(;(int)chn.size() < n;) {
		int pos = 1;
		for(int i = 2; i <= m; ++i)
			if(h[i].size() > h[pos].size())
				pos = i;
		ans += f((long long)h[pos].size());
		if((int)(h[pos].size() + chn.size()) == n)
			break;
		for(int x : h[pos]) {
			chn.insert(x);
			for(int i = 1; i <= m; ++i) {
				if(i == pos) continue;
				h[i].erase(x);
			}
		}
		h[pos].clear();
	}
	printf("%lld", ans);
	return 0;
}

