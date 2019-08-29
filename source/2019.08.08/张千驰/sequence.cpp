#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long ans=0;

template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int a[1010],n,l,r,s,e;

int main()
{
	int n,q;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	memset(a,0,sizeof(a));
	read(n);
	read(q);
	for (register int i=1;i<=q;++i)
	{
		read(l),read(r),read(s),read(e);
		int d=(e-s)/(r-l);	
		for (register int j=l;j<=r;++j)
			a[j]+=s+(j-l)*d;

	}
	
	ans=a[1];
	for (register int i=2;i<=n;++i)
		ans^=a[i];
	printf("%lld\n",ans);
	return 0;
}

