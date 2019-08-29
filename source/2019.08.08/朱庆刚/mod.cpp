#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long f(long long n, long long p) {
	if(n == 1) return 0;
	long long res = n * f(n - 1, p) % p;
	for(int i = 1; i < n; ++i) {
		long long pa = i == n ? n - 1 : n, pb = 1;
		long long tmp = 1;
		for(int j = 1; j < n; ++j) {
			if(pa != pb) ++tmp;
			--pa;
			++pb;
			if(pa == i) --pa;
			if(pb == i + 1) ++pb;
		}
		tmp %= p;
		res += tmp;
		res %= p;
	}
	return res;
}

int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		long long n, p;
		scanf("%lld %lld", &n, &p);
		printf("%lld\n", f(n, p));
	}
	return 0;
}

