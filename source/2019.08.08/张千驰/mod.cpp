#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long p,a[3001]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};

template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	long long n,q;
	read(q);
	for (register int i=1;i<=q;++i)
	{
		long long ans=0;
		read(n);
		read(p);
		printf("%lld\n",a[n]%p);
	}
	return 0;
}

