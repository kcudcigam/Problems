#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int read(){
	char c=getchar();while(!isdigit(c))c=getchar();
	int num=0;while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num;
}
int to1[200001], to2[200001];
int cnt1[200001][2], cnt2[200001];
bool vis[200001];
long long fact[200001];
long long power(long long a, int n) {
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1; 
	}
	return ans;
}
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	int Num = read();
	int n, m1, m2;
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; i++) {
		int x, y;
		x = read(), y = read();
		to1[x] = y, to1[y] = x;
	}
	for (int i = 1; i <= m2; i++) {
		int x, y;
		x = read(), y = read();
		to2[x] = y, to2[y] = x;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (!to1[i] && !to2[i]) {
			vis[i] = 1;
			++cnt1[1][0];
			continue;
		}
		if (!to1[i]) {
			vis[i] = 1;
			int p = 1, ct = 1;
			for (int j = to2[i]; j ; j = p?to2[j]:to1[j]) ++ct, p=1-p, vis[j]=1;
			if ((ct & 1) == 0) ++cnt1[ct][1];
			else ++cnt1[ct][0];
		}
		if (!to2[i]) {
			vis[i] = 1;
			int p = 0, ct = 1;
			for (int j = to1[i]; j ; j = p?to2[j]:to1[j]) 
			++ct, p=1-p, vis[j]=1;
			++cnt1[ct][0];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		int p = 0, ct = 1;
		for (int j = to1[i]; !vis[j] ; j = p?to2[j]:to1[j]) ++ct, p=1-p, vis[j] = 1;
		++cnt2[ct];
	}
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
	long long ans = 1;
	for (int i = 0; i <= n; i++) {
		ans = ans * fact[cnt2[i]] % mod * power(i, cnt2[i]) % mod;
		if ((i & 1) == 0) ans=ans*(fact[cnt1[i][0]]*power(2,cnt1[i][0])%mod)%mod*(fact[cnt1[i][1]]*power(2,cnt1[i][1])%mod)%mod;
		else ans = ans * fact[cnt1[i][0]] % mod;
	}
	cout << (fact[n] - ans + mod) % mod << endl;
}
