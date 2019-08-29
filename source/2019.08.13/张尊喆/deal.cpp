#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int P = 1000000007;
#define ll long long
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

const int N = 10005;
ll f[N]; // y-x a b
ll dp[N];
int a[N], b[N], c[N];
int n, x;

int main() {
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n = read(), x = read();
	for (int i = 1;i <= n; i++) 
	a[i] = read(), b[i] = read(), c[i] = read();
	f[0] = 1;
	for (int i = 1;i <= n; i++)
		for (int k = x * 2; k >= 0; k--)
			for (int j = 1;j <= c[i]; j++)
			if (k >= j*a[i]) {
				f[k] += f[k-j*a[i]];
				f[k] %= P;
			}
	ll ans = 0, la = n;
	for (la = n;la >= 1; la--) {
		if (a[la] < x) break;
	}
	for (int i = x;i >= 0; i--) {
		dp[0] = 1;
		if (a[la] > i && la)
		{ 
			for (int k = x + i;k >= 0; k--) 
				for (int j = 1;j <= b[la]; j++)
					if (k >= j*a[la]) {
						dp[k] += dp[k-j*a[la]];
						dp[k] %= P;
					}
			la--;
		}
		ans += dp[x+i] * f[i];
		ans %= P;
	}
	//for (int i = 1;i <= max(x*2, a[n]); i++) cout << f[i] << ' ';
	cout << ans << endl;
	return 0;
}
	
	
	
	
	
	
	
	
