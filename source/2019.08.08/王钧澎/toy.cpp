#include<bits/stdc++.h>
#define MAXM 1000010
#define MAXN 1010
#define inf INT_MAX / 3;

using namespace std;

int n , m;
int f[MAXN][MAXN];
int a[MAXN];
int pre[MAXN];
int ans;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }
template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
 
int main(){

	freopen("toy.in" , "r" , stdin);
	freopen("toy.out" , "w" , stdout);

	read(n); read(m);
	
	for (int i = 1; i <= n; i++) pre[i] = inf;
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++) f[i][j] = inf;
	
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	
	f[1][1] = a[1];
	if (f[1][1] <= m) ans = 1;
	f[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		f[i][1] = a[i];
		f[i][0] = 0;
		for (int j = 1; j <= i; j++) {
			chkmin(f[i][j] , pre[j - 1] + a[i]);
			if (f[i][j] <= m && j > ans) ans = j;
			chkmin(pre[j - 1] , f[i - 1][j - 1]);
		}
		chkmin(pre[i] , f[i - 1][i]);
		for (int j = 1; j <= i; j++) {
			chkmin(f[i][j] , pre[j]);
			if (f[i][j] <= m && j > ans) ans = j;
		}
	}

	cout << ans << endl;

	return 0;
}


