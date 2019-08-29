#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1000000007;

int main(){
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	LL n, m; cin >> n >> m;
	LL ans = 1;
	for (LL i = m - 1; i > 1; --i) ans = (ans * i) % mod;
	cout << ans << endl;

	return 0;
}



