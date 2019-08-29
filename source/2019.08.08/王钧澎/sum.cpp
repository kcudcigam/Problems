#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010

using namespace std;

int n;
int a[MAXN];
ll sum[MAXN] , pre[MAXN];
ll msum[MAXN] , mpre[MAXN];
ll lans[MAXN] , rans[MAXN];

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

int main(){

	freopen("sum.in" , "r" , stdin);
	freopen("sum.out" , "w" , stdout);

	read(n);
	
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		pre[i] = pre[i - 1] + a[i];
		mpre[i] = min(mpre[i - 1] , pre[i]);
	}
	
	for (int i = n; i >= 1; i--) {
		sum[i] = sum[i + 1] + a[i];
		msum[i] = min(msum[i + 1] , sum[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		lans[i] = max(lans[i - 1] , pre[i] - mpre[i]);
	}
	
	for (int i = n; i >= 1; i--) {
		rans[i] = max(rans[i + 1] , sum[i] - msum[i]);
	}
	
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		chkmax(ans , lans[i] + rans[i + 1]);
	}
	
	cout << ans << endl;

	return 0;
}

