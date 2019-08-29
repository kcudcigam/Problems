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

priority_queue<ll> q;
ll liknum[670000], tot;
ll n;

void prework(int a, int b) {
	for (reg int l=2; l<=13-(b==0); ++l)
		for (reg int k=1-(b==0); k<(1<<l)-1; ++k) {
			ll x=((b==0)?a:0);
			for (reg int i=1; i<=l; ++i) x=x*10+(((k>>i-1)&1)?a:b);
			q.push(-x);
		}
}

void solve() {
	n=read();
	int pos1=upper_bound(liknum+1, liknum+1+tot, n)-(liknum+1), pos2;
	if (liknum[pos1]==n) { printf("1\n"); return; }
	for (; pos1; --pos1) {
		pos2=upper_bound(liknum+1, liknum+1+tot, n-liknum[pos1])-(liknum+1);
		if (liknum[pos1]+liknum[pos2]==n) { printf("2\n"); return; }
	}
	printf("3\n"); return;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (reg int i=1; i<=9; ++i) {
		ll x=0;
		for (reg int l=1; l<=13; ++l) x=x*10+i, q.push(-x);
	}
	q.push(-10);
	for (reg int i=1; i<=9; ++i)
		for (reg int j=0; j<i; ++j) prework(i, j);
	while (q.size()) liknum[++tot]=-q.top(), q.pop();
	liknum[++tot]=10000000000000ll;
	for (reg int T=read(); T; --T) solve();
	return 0;
}

