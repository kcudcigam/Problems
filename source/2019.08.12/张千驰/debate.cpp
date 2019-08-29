#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long ans=0;
int n,a,val,cnt=0,cnt01=0,cnt10=0,cnt00=0,a01[400010],a00[400010],a10[400010];

int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&a,&val);
		if (a==0)
			a00[++cnt00]=val;
		if (a==1)
			a01[++cnt01]=val;
		if (a==10)
			a10[++cnt10]=val;
		if (a==11)
		{
			ans+=val;
			++cnt;
		}
	}
	sort(a00+1,a00+cnt00+1);
	sort(a01+1,a01+cnt01+1);
	sort(a10+1,a10+cnt10+1);
	while (cnt10>=1 && cnt01>=1)
		ans+=a10[cnt10--]+a01[cnt01--];
	if (cnt10==0 && cnt10==0)
	{
		while (cnt--)
			ans+=a00[cnt00--];
		printf("%lld\n",ans);
		return 0;
	}
	if (cnt10==0 && cnt01!=0)
	{
		while (cnt--)
		{
			if (a01[cnt01]>a00[cnt00])
			{
				ans+=a01[cnt01];
				--cnt01;
			}
			else
			{
				ans+=a00[cnt00];
				--cnt00;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	if (cnt01==0 && cnt10!=0)
	{
		while (cnt--)
		{
			if (a10[cnt10]>a00[cnt00])
			{
				ans+=a10[cnt10];
				--cnt10;
			}
			else
			{
				ans+=a00[cnt00];
				--cnt00;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}


