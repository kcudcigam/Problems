#include<bits/stdc++.h>
#define ll long long
#define MAXN 1010

using namespace std;

int n , A , B , C , D;
ll ans;
ll f[MAXN][MAXN];
int a[MAXN];
int minn;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

int main() {

	freopen("min.in" , "r" , stdin);
	freopen("min.out" , "w" , stdout);

	read(n); read(A); read(B); read(C); read(D);
	if (A == 0 && B == 0 && C <= 0) {
		minn = INT_MAX;
		for (int i = 1; i <= n; i++) {
			int x; read(x);
			chkmin(minn , x);
			if (C * x + D > 0) {
				ans += C * x + D;
			}
		}
		if (ans) cout << ans << endl;
		else cout << minn * C + D << endl;
	}

	return 0;
}

