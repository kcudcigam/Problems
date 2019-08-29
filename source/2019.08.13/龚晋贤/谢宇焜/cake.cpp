#include<bits/stdc++.h>
#define fir(a, b, c) for(register int a = b; a <= c; a ++)
#define ll long long
using namespace std;
inline int read(){
	int x = 0, ff = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if (c == '-') ff = -1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return ff*x;
}
const int MOD = 1e9+7;
ll f[305][305];
ll ans;

ll dfs(int n, int m)
{
	if(f[n][m]) return f[n][m];
	if(n == 1 && m == 1) return f[1][1] = 1ll;
	ll res = 0ll;
	fir(i, 1, n-1)
		res = (res + (dfs(i, m)*dfs(n-i,m))%MOD)%MOD;
	fir(i, 1, m-1)
		res = (res + (dfs(n, i)*dfs(n,m-i))%MOD)%MOD;
	return f[n][m] = res%MOD;
}

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n, m;
	n = read(), m = read();
	cout<<dfs(n, m)<<endl;
	return 0;
}

