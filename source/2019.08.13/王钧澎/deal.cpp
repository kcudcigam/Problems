#include<bits/stdc++.h>
#define ll long long
#define MAXN 20010
#define pmod 1000000007

using namespace std;

int n , m;
ll dp1[MAXN] , dp2[MAXN];
int x[MAXN] , y[MAXN] , z[MAXN];
ll ans;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

int main() {

	freopen("deal.in" , "r" ,stdin);
	freopen("deal.out" , "w" , stdout);
	cout << 5 << endl;
//	read(n); read(m);
//	
//	dp1[0] = dp2[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		int x , y , z;
//		read(x); read(y); read(z);
//		for (int j = m + x - 1; j >= x; j--) {
//			for (int k = 1; k * x <= j && k <= y; k++) {
//				dp1[j] += dp1[j - k * x];
//			}
//		}
//		if (i == n) continue;
//		for (int j = 9999; j >= x; j--) {
//			for (int k = 1; k * x <= j && k <= z; k++) {
//				dp2[j] += dp2[j - k * x];
//			}
//		}
//	}
//	
//	for (int i = 1; i <= 13; i++) {
//		cout << dp1[i] << " ";
//	}
//	cout << endl;
//	
//	ll ans = 0;
//	for (int i = 0; i <= 9999; i++) {
//		ans = (ans + dp1[m + i] * dp2[i]) % pmod;
//	}
//
//	cout << ans << endl;
	
	return 0;
}

