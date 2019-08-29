#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int P = 1000000007;
const int N = 205;
ll f[N][N];
int n, m;
int main() {
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin >> n >> m;
	f[1][1] = 1;
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			for (int k = 1;k < i; k++) 
			f[i][j] += (f[k][j] * f[i-k][j]) % P;
			for (int k = 1;k < j; k++) 
			f[i][j] += (f[i][k] * f[i][j-k]) % P;
			f[i][j] %= P;
		}
	}
	cout << f[n][m] % P << endl;
	return 0;
}
