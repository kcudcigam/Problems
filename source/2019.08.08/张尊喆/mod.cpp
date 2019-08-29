#include<bits/stdc++.h>
using namespace std;
const int N = 10000007;
int prime[N], e[N], jie[N], tot;
long long f[N];
long long q[45], p[45], maxn;
int main() {
	int T;
	cin >> T;
	for (int i = 1;i <= T; i++) {
		cin >> q[i] >> p[i];
		maxn = max(maxn, q[i]);
	}
	for (int i = 2;i <= maxn; i++) {
		if (!e[i]) prime[++tot] = e[i] = i;
		for (int j = 1;j <= tot; j++) {
			if (prime[j] > e[i] || prime[j] * i > maxn) break;
			e[prime[j] * i] = prime[j];
		}
	}
	for (int l = 1;l <= T; l++) {
		jie[1] = 1;
		for (int i = 2;i <= q[i]; i++) jie[i] = jie[i-1] * i, jie[i] %= p[l];
		f[1] = f[2] = 0;
		f[3] = 3;
		for (int i = 4;i <= q[l]; i++) {
			f[i] = i * f[i-1] + jie[i] - e[i];
			f[i] %= p[l];
		}
		long long ans = q[l] * (jie[q[l]] - 1) % p[l] - f[q[l]];
		ans %= p[l];
		ans += p[l];
		ans %= p[l];
		cout << ans << endl;
	}
	return 0;
}
