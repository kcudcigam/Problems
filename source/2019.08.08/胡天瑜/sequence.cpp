#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;

long long n,m;
long long a[MAXN];
long long ans=0;

template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;++i)
	{
		long long l,r,s,e;
		read(l);read(r);read(s);read(e);
		for(int i=l;i<=r;++i)
		{
			a[i]+=s+(e-s)/(r-l)*(i-l);
		}
	}
	for(int i=1;i<=n;++i)
	{
		ans=ans^a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
