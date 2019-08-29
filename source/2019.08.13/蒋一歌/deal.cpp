#include <bits/stdc++.h>
#define Maxn	1050
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int mod = 1000000007;
int Mod(int x){ return x >= mod ? x - mod : x; }
int dMod(int x){ return x < 0 ? x + mod : x; }
void Inc(int &x, int y){ x = Mod(x + y); }
void Dec(int &x, int y){ x = dMod(x - y); }

int f[Maxn][20500], g[Maxn][10500];
int a[Maxn], b[Maxn], c[Maxn];
int n, X, W, Ans;

int main(){
	freopen("deal.in", "r", stdin); freopen("deal.out", "w", stdout);
	read(n), read(X);
	for (int i = 1; i <= n; i++)
		read(a[i]), read(b[i]), read(c[i]), W = max(W, a[i]);
	
	g[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= W; j++){
		int lst = j - a[i], lc = lst / a[i];
		if (lst < 0){ g[i][j] = g[i - 1][j]; continue; }
		g[i][j] = Mod(g[i - 1][j] + g[i][lst]);
		if (lc >= c[i]) Dec(g[i][j], g[i - 1][lst - c[i] * a[i]]);
	}
	
	reverse(a + 1, a + n + 1), reverse(b + 1, b + n + 1), reverse(c + 1, c + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= W + X; j++){
		int lst = j - a[i], lc = lst / a[i];
		if (lst < 0){ f[i][j] = f[i - 1][j]; continue; }
		f[i][j] = Mod(f[i - 1][j] + f[i][lst]);
		if (lc >= b[i]) Dec(f[i][j], f[i - 1][lst - b[i] * a[i]]);
	}
	
	for (int d = W - 1, pos = 0; d >= 0; d--){
		while (pos < n && a[pos + 1] > d) pos++;
		Inc(Ans, 1ll * f[pos][d + X] * g[n][d] % mod);
	}
	cout << Ans << '\n';
	return 0;
}
