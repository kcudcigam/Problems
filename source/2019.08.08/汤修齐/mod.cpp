#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e7 + 10;

int n;
LL MOD;
LL f[maxn];

void work(){
	scanf("%d%lld", &n, &MOD);
	for (int i = 2; i <= n; i++){
		f[i] = i * (i - 1) + f[i - 1] * i;
		if (!(i & 1)) f[i] -= i - 2;
		f[i] %= MOD;
	}
	printf("%lld\n", f[n]);
}

int main(){
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}
