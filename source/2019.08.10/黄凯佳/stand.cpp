#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do x=x*10+c-48; while (isdigit(c=getchar()));
	return x*f;
}

const int N = 250 + 5;

struct node {
	int l, r;
}a[N];

int n, m, pos[N], mark2[N]; ll g[10], res;

ll calc(ll x) {
	return g[1]*x+g[2]*x*x+g[3]*x*x*x+g[4]*x*x*x*x+g[5]*x*x*x*x*x;
}

void solve_bf(int x) {
	if (x==n+1) {
		ll tmp=0;
		for (reg int i=1; i<=m; ++i) tmp+=calc(mark2[i]);
		res=max(res, tmp);
		return;
	}
	for (reg int i=a[x].l; i<=a[x].r; ++i) ++mark2[i], solve_bf(x+1), --mark2[i];
	return;
}

inline bool comp1(const node &a1, const node &a2) {
	return a1.l>a2.l;
}

ll solve1() {
	map<int, int> stor;
	map<int, bool> mark;
	memset(pos, 0, sizeof(pos));
	ll ans=0;
	sort(a+1, a+1+n, comp1);
	for (reg int i=1; i<=n; ++i) {
		int t1=a[i].l, t2=0;
		for (reg int j=i-1; j; --j) {
			if (pos[j]>a[i].r) continue;
			if (stor[pos[j]]>t2) t2=stor[pos[j]], t1=pos[j];
			else if (stor[pos[j]]==t2 && pos[j]<t1) t1=pos[j];
		}
		++stor[t1]; pos[i]=t1;
	}
	for (reg int i=1; i<=n; ++i)
		if (!mark[pos[i]]) ans+=calc(stor[pos[i]]), mark[pos[i]]=1;
	return ans;
}

inline bool comp2(const node &a1, const node &a2) {
	return a1.l<a2.l;
}

ll solve2() {
	ll ans=0;
	sort(a+1, a+1+n, comp2);
	int t1=a[1].r, sum=1;
	for (reg int i=2; i<=n; ++i) {
		if (a[i].l>t1) { ans+=calc(sum); t1=a[i].r; sum=1; }
		else { t1=min(t1, a[i].r); ++sum; } 
	}
	ans+=calc(sum);
	return ans;
}

inline bool comp3(const node &a1, const node &a2) {
	return a1.r>a2.r;
}

ll solve3() {
	ll ans=0;
	sort(a+1, a+1+n, comp3);
	int t1=a[1].l, sum=1;
	for (reg int i=2; i<=n; ++i) {
		if (a[i].r<t1) { ans+=calc(sum); t1=a[i].l; sum=1; }
		else { t1=max(t1, a[i].l); ++sum; } 
	}
	ans+=calc(sum);
	return ans;
}

inline bool comp4(const node &a1, const node &a2) {
	return a1.r<a2.r;
}

ll solve4() {
	map<int, int> stor;
	map<int, bool> mark;
	memset(pos, 0, sizeof(pos));
	ll ans=0;
	sort(a+1, a+1+n, comp4);
	for (reg int i=1; i<=n; ++i) {
		int t1=a[i].r, t2=0;
		for (reg int j=i-1; j; --j) {
			if (pos[j]<a[i].l) continue;
			if (stor[pos[j]]>t2) t2=stor[pos[j]], t1=pos[j];
			else if (stor[pos[j]]==t2 && pos[j]>t1) t1=pos[j];
		}
		++stor[t1]; pos[i]=t1;
	}
	for (reg int i=1; i<=n; ++i)
		if (!mark[pos[i]]) ans+=calc(stor[pos[i]]), mark[pos[i]]=1;
	return ans;
}

int main() {
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	n=read(); m=read();
	for (reg int i=1; i<=5; ++i) g[i]=read();
	for (reg int i=1; i<=n; ++i) a[i].l=read(), a[i].r=read();
	if (n<=9 && m<=9) solve_bf(1);
	else {
		ll ans1=solve1(), ans2=solve2(), ans3=solve3(), ans4=solve4();
		res=max(ans1, max(ans2, max(ans3, ans4)));
	}
	printf("%lld\n", res);
	return 0;
}

