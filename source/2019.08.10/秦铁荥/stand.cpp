#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int re=0; bool f=1; char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f = 0; c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return f ? re : -re;
}

const int N = 1e3;
const ll inf = 1LL << 60;
int n, m, g[10], l[N], r[N], p[N], len, ud[N], MS;
ll ans, f[(int)2e5][21];

ll _res, _s;
inline ll G(int x) {
	_res = 0, _s = 1;
	fox (i, 1, 5) _s *= x, _res += _s * g[i];
	return _res;
}

ll _ss;
void dfs(int x) {
	if (x > n) {
		_ss = 0;
		fox (i, 1, len) _ss += G(ud[i]);
		ans = max(ans, _ss);
		return;
	}
	fox (i, l[x], r[x]) {
		++ud[i];
		dfs(x + 1);
		--ud[i];
	}
}

ll ddd(int S, int ps) {
	if (S == 0) return 0;
	if (ps < 1) return -inf;
	int s = 0, SS = S;
	ll ss = ddd(S, ps - 1);
	fox (i, 1, n) if (S & (1 << (i - 1))) {
		if (l[i] > ps || ps > r[i]) continue;
		++s, SS -= (1 << (i - 1));
		ss = max(ss, G(s) + ddd(SS, ps - 1));
	}
	return f[S][ps] = ss;
}

int q[6][6];
void sfd(int l, int r) {
	if (l > r) {
		ll s = 0;
		fox (i, 1, len) s += G(ud[i]);
		ans = max(s, ans);
		return;
	}
	fox (i, l, r) {
		ud[i] += q[l][r];
		if (l ^ 1) sfd(l - 1, r - 1);
		else sfd(len - r + l + 1, len);
		ud[i] -= q[l][r];
	}
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n = rd(), m = rd();
	fox (i, 1, 5) g[i] = rd();
	fox (i, 1, n) l[i] = rd(), r[i] = rd();
	fox (i, 1, n) p[++len] = l[i], p[++len] = r[i];
	sort(p + 1, p + len + 1); len = unique(p + 1, p + len + 1) - p - 1;
	fox (i, 1, n) l[i] = lower_bound(p + 1, p + len + 1, l[i]) - p;
	fox (i, 1, n) r[i] = lower_bound(p + 1, p + len + 1, r[i]) - p;
	
	if (len == 2) {
		printf("%lld\n", G(n));
		return 0;
	}
	
	if (n <= 10 && len <= 10) {
		dfs(1);
		printf("%lld\n", ans);
		return 0;
	}
	
	if (n <= 15 && len <= 20) {
		fox (i, 1, n) fox (j, i + 1, n) 
			if (l[i] < l[j]) swap(l[i], l[j]), swap(r[i], r[j]);
		MS = (1 << n) - 1;
		printf("%lld\n", ddd(MS, len));
		return 0;
	}
	
	if (n <= 40 && len <= 5) {
		fox (i, 1, n) q[l[i]][r[i]]++;
		sfd(1, len);
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}
