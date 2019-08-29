#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005, P = 1e9+7;
int p[2][N], h[N];
int dfs(int num, int w){
	h[num] = -1;
	if (!p[w^1][num]) return 1;
	return dfs(p[w^1][num], w^1)+1;
}
int spdfs(int num, int w, int clr){
	if (h[num] == clr) return 0;
	h[num] = clr;
	return spdfs(p[w^1][num], w^1, clr)+1;
}
ll sppow(ll a, ll b){
	ll s = 1, x = a;
	for (ll d = b; d; d /= 2, x = (x*x)%P)
		if (d%2) s *= x;
	return s;
}
ll jc[N], f2[N], f[4][N];
int t, n, x, y, m1, m2;
ll ans, cnt;
int main(){
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	cin >> t >> n >> m1 >> m2;
	jc[0] = f2[0] = 1;
	for (int i = 1; i <= n; i++){
		jc[i] = (jc[i-1]*i)%P;
		f2[i] = (f2[i-1]*2)%P;
	}
	for (int i = 1; i <= m1; i++){
		cin >> x >> y;
		p[0][x] = y;
		p[0][y] = x;
	}
	for (int i = 1; i <= m2; i++){
		cin >> x >> y;
		p[1][x] = y;
		p[1][y] = x;
	}
	for (int i = 1; i <= n; i++){
		if (h[i] == 0 && p[0][i] && !p[1][i]){
			t = dfs(i, 1);
			if (t%2 == 0)
				f[0][t/2]++; else
		 		f[2][t/2]++;
		}
		if (h[i] == 0 && p[1][i] && !p[0][i]){
			t = dfs(i, 0);
			if (t%2 == 0)
				f[1][t/2]++; else
				f[2][t/2]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (h[i] == 0 && p[1][i] && p[0][i]){
			t = spdfs(i, 0, i);
			f[3][t]++;
		}
	for (int i = 1; i <= n; i++) if (h[i] == 0) cnt++;
	ans = 1;
	for (int i = 1; i <= n; i++){
		if (f[0][i]){
			x = f[0][i];
			ans = ans*f2[x]%P*jc[x]%P;
		}
		if (f[1][i]){
			x = f[1][i];
			ans = ans*f2[x]%P*jc[x]%P;
		}
		if (f[2][i]){
			x = f[2][i];
			ans = ans*jc[x]%P;
		}
		if (f[3][i]){
			x = f[3][i];
			ans = ans*sppow(i, x)%P*jc[x]%P;
		}
	}
	cout << (jc[n]+P-ans*jc[cnt]%P)%P << endl;
	return 0;
}


