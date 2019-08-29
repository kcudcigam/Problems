#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 998244353;
LL n, ans, ls;
string s;

LL qsm(LL a, LL b) {
	if (b < 0) return 0;
	int sum = 1;
	for (; b; b >>= 1) {
		if (b & 1) sum = (sum * a) % mod;
		a = (a * a) % mod;
	}
	return sum;
}

int main(){
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	cin >> n >> s;
	ls = s.length();
	
	LL n25 = 25, n26 = 26, nls1 = ls - 1;
	ans = qsm(n26, n - 1) - qsm(n26, n - ls - 1);
	if (ans < 0) ans += mod;
	ans = (ans * n25) % mod;
	
	LL cnt;
	if (ls == n) cnt = 1;
	else {
		cnt = (cnt + qsm(n26, n - ls) * ls % mod) % mod;
		cnt -= qsm(n26, n - ls - 1) * nls1 % mod;
		if (cnt < 0) cnt += mod;
	}
	
	ans = (ans + qsm(n26, n - 1)) % mod;
	ans -= cnt;
	if (ans < 0) ans += mod;
	
	cout << ans << endl;

	return 0;
}



