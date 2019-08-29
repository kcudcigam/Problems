#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,A,B,C,D,ans,beg=1;
ll a[200010],b[200010];//a: Ô­Êý×é; b: f(a[i]);
ll b_1[200010];
ll f(ll x)
{
	ll rtn;
	rtn=A*x*x*x+B*x*x+C*x+D;
	return rtn;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	scanf("%lld %lld %lld %lld %lld",&n,&A,&B,&C,&D);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=f(a[i]);
	}
	
	int i=n;
	while(f(a[i])>0&&i)
	{
		ans+=f(a[i]);
		i--;n--;
	}
	i=1;
	while(f(a[i])>0&&i<=n)
	{
		ans+=f(a[i]);
		i++;beg++;
	}
	
	
	ll minn=LLONG_MAX,tempm=0;
	ll ti=1;
	for(int i=beg;i<=n+1;i++)
	{
		if((i>beg &&   ((b[i]>0&&b[i-1]<0)||b[i]<0&&b[i-1]>0)   )||i==n+1)
		{
			if(b[i-1]<0)
			{
				b_1[ti]=f(minn);
				minn=LLONG_MAX;
				ti++;
			}
			else
			{
				b_1[ti]=tempm;
				tempm=0;
				ti++;
			}
		}
		if(b[i]<0)
		{
			minn=min(minn,a[i]);
		}
		if(b[i]>=0)
		{
			tempm+=b[i];			
		}
	}
	
	ans+=b_1[1];
	for(int i=2;i<ti;i=i+2)
	{
		if(b_1[i]+b_1[i+1]>=0)
		{
			ans+=b_1[i]+b_1[i+1];
		}
	}
	
	
	printf("%lld\n",ans);
	
	return 0;
}

