#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	int n, n0, k;
	long long ans = 0;
	cin >> n >> k;
	n0 = n;
	while (n0) {
		k -= n0 & 1;
		n0 >>= 1;
	}
	int p = n & -n;
	while (k < 0) {
		ans += p;
		while (n & p) ++k, p <<= 1;
		n |= p;
		--k;
	}
	cout << ans << endl;
	return 0;
}

