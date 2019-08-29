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

const int N = 400000 + 5;

int n, p[N], inq[N];
ll sco[N], ans;
priority_queue< pair<ll, int> > a, b, c, d;

ll check(ll x) {
	ll res=0;
	for (reg int i=1; i<=n; ++i)
		if (!inq[i]) {
			pair<ll, int> t=make_pair(sco[i], i);
			if (p[i]==11) a.push(t);
			else if (p[i]==10) b.push(t);
			else if (p[i]==1) c.push(t);
			else d.push(t);
			inq[i]=1;
		}
	int cnt=0;
	for (reg int i=1; i<=(x>>1)+(x&1); ++i) {
		if ((!b.size() || !c.size()) && !a.size()) return -1;
		if (!a.size()) {
			cnt+=2; res+=b.top().first+c.top().first;
			//printf("%d %d ", b.top().second, c.top().second);
			inq[b.top().second]=0; b.pop();
			inq[c.top().second]=0; c.pop();
			continue;
		}
		if (!b.size() || !c.size()) {
			cnt+=1; res+=a.top().first;
			//printf("%d ", a.top().second);
			inq[a.top().second]=0; a.pop();
			continue;
		}
		int t1=a.top().second, t2=0, flag=0; a.pop();
		if (a.size() && a.top().first>sco[t2]) flag=1, t2=a.top().second;
		if (b.size() && b.top().first>sco[t2]) flag=2, t2=b.top().second;
		if (c.size() && c.top().first>sco[t2]) flag=3, t2=c.top().second;
		if (d.size() && d.top().first>sco[t2]) flag=4, t2=d.top().second;
		if (sco[t1]+sco[t2]<b.top().first+c.top().first) {
			cnt+=2; res+=b.top().first+c.top().first;
			inq[b.top().second]=0; b.pop();
			inq[c.top().second]=0; c.pop();
			a.push(make_pair(sco[t1], t1));
			continue;
		}
		inq[t1]=0;
		//printf("%d ", t1);
		if (flag==1) cnt+=2, ++i, res+=sco[t1]+sco[t2], inq[t2]=0/*, printf("%d ", t2)*/, a.pop();
		else cnt+=1, res+=sco[t1];
	}
	while (cnt<x) {
		int t=0, flag=0;
		if (a.size() && a.top().first>sco[t]) flag=1, t=a.top().second;
		if (b.size() && b.top().first>sco[t]) flag=2, t=b.top().second;
		if (c.size() && c.top().first>sco[t]) flag=3, t=c.top().second;
		if (d.size() && d.top().first>sco[t]) flag=4, t=d.top().second;
		inq[t]=0; res+=sco[t];
		if (flag==1) a.pop();
		if (flag==2) b.pop();
		if (flag==3) c.pop();
		if (flag==4) d.pop();
		//printf("%d ", t);
		++cnt;
	}
	return res;
}

int main() {
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	n=read();
	for (reg int i=1; i<=n; ++i) p[i]=read(), sco[i]=read();
	int l=1, r=n;
	while (l<=r) {
		int mid=(l+r)>>1; //printf("%d\n", mid);
		ll calc=check(mid); //printf("\n");
		if (calc==-1) r=mid-1;
		else ans=max(ans, calc), l=mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}

