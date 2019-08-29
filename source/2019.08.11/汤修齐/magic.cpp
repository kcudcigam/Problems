#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 998244353;
const int maxn = 110;

LL n;
int f[maxn][maxn];
char s[maxn];

inline LL qpow(LL x, int y){
	int re = 1;
	for (; y; y >>= 1){
		if (y & 1) re = re * x % MOD;
		x = x * x % MOD;
	}
	return re;
}

int main(){
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%s", s);
	int len = strlen(s);
	
	if (len == n){
		printf("%lld\n", (qpow(26, n) - 1 + MOD) % MOD);
		return 0;
	}
	LL tot = qpow(26, n), cnt = qpow(26, n - len), val = 0, siz = n - len;
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j <= len; j++){
			f[i][j] = (j - i) & 1;
			for (int k = i + siz; k < j && f[i][j]; k++)
				if (s[k] != s[k - siz]) f[i][j] = 0;
		}
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j <= len; j++)
			val = (val + f[i][j] * qpow(26, siz - j + i));
	printf("%lld\n", (tot - cnt * (len + 1) % MOD + val + MOD) % MOD);
	return 0;
}
