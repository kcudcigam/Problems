#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int mod = 1e9 + 7;
const int N = 3e2 + 5;
LL f[N][N];
int n, m;
int main(){
	freopen ("cake.in", "r", stdin);
	freopen ("cake.out", "w", stdout);
	read(n); read(m);
	f[1][1] = 1;
	
	for (int i = 1; i <= n; i++)
	 for (int j = 1; j <= m; j++)
	 {
	 	for (int k = 1; k < i; k++) f[i][j] = (f[i][j] + f[k][j] * f[i - k][j] % mod) % mod;
	 	
	 	for (int k = 1; k < j; k++) f[i][j] = (f[i][j] + f[i][k] * f[i][j - k] % mod) % mod;
	 }
	printf("%lld\n", f[n][m]);
  return 0;
}
