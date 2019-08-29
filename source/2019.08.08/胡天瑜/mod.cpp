#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int q;
long long n,p;

int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%d",&q);
	while(q>0)
	{
		--q;
		scanf("%lld%lld",&n,&p);
		long long ans=0;
		for(long long i=1;i<=n;++i)
		{
			if(i&1)
			{
				ans=i*ans+(i-1)*i;
				if(ans>p) ans=ans%p;
			}
			else
			{
				ans=i*ans+(i-1)*i-(i-2);
				if(ans>p) ans=ans%p;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

