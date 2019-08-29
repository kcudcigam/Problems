#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 2e5 + 10;
int n, a[N], mn[N], tp;
ll A, B, C, D, f[N], ff[N];
priority_queue<ll> q, qdel;

ll F(ll x) {return ((A * x + B) * x + C) * x + D;}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n = rd(), A = rd(), B = rd(), C = rd(), D = rd();
	fox (i, 1, n) a[i] = rd();
	
	ll maxs = 0, S;
	fox (i, 1, n) {
		S = f[i - 1];
		while (tp && a[mn[tp]] > a[i]) {
			S = max(S, ff[tp]);
			qdel.push(ff[tp] + F(a[mn[tp]]));
			--tp;
		}
		mn[++tp] = i, ff[tp] = S;
		q.push(ff[tp] + F(a[i]));
		while (!qdel.empty() && q.top() == qdel.top()) q.pop(), qdel.pop();
		f[i] = q.top();
	}
	
	printf("%lld\n", f[n]);
	return 0;
}
