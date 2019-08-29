#include<cstdio>
#include<iostream>
using namespace std;

const long long MO = 1000000007;

long long rem[301][301];

long long f(int x, int y) {
	if(x > y) swap(x, y);
	if(rem[x][y] > 0) return rem[x][y];
	long long res = 0LL;
	for(int i = 1; i < x; ++i) {
		res += (f(i, y) * f(x - i, y)) % MO;
		res %= MO;
	}
	for(int i = 1; i < y; ++i) {
		res += (f(x, i) * f(x, y - i)) % MO;
		res %= MO;
	}
	return rem[x][y] = res;
}

int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	rem[1][1] = 1LL;
	printf("%lld", f(n, m));
	return 0;
}
