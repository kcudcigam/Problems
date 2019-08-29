#include<bits/stdc++.h>
using namespace std;
#define N 310
#define mod 1000000007
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
template <typename T> inline void read(T &n){
	n = 0; T f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
int n, m;
long long f[N][N];
int main(){
	FO("cake");
	read(n), read(m);
	f[1][1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			for (int k = 1; k < i; ++k)
				f[i][j] = (f[i][j] + f[k][j] * f[i - k][j] % mod) % mod;
			for (int k = 1; k < j; ++k)
				f[i][j] = (f[i][j] + f[i][k] * f[i][j - k] % mod) % mod;
		}
	cout << f[n][m] << endl;
	return 0;
}
