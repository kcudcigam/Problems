#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}

const int N = 100005;
ll a[N], f[N], r[N], n;

int main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) {
		f[i] = a[i];
		f[i] = max(f[i], f[i-1] + a[i]);
//		cout << f[i] << endl;
	}
	for (int i = n;i >= 1; i--) {
		r[i] = a[i];
		r[i] = max(r[i], r[i+1] + a[i]);
	}
	for (int i = 1;i <= n; i++) f[i] = max(f[i], f[i-1]);
	for (int i = n;i >= 1; i--) r[i] = max(r[i], r[i+1]);
	ll ans = a[1] + a[2];
	for (int i = 1;i < n; i++) {
		ans = max(ans, f[i] + r[i+1]);
	}
	cout << ans << endl;
	return 0;
}
		
		
		
		
