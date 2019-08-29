#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int num=0,f=1;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const ll mod=1000000007;
ll f[50000+7];
ll d[50000+7];
int a[1000+7],b[1000+7],c[1000+7];
int tot=0;
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	R int n=read(),X=read();
	R int sum1=0,sum2=0;
	for(R int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
	}
	int mixx=0,pos=0,sum=0;
	for(R int i=1;i<=n;i++)
	{
		R int res=(X-sum1)/a[i];
		if(res>=b[i])sum1+=a[i]*b[i];
		else sum1+=a[i]*(res+1);
		
		if(sum1+a[i]>X)
		{
			if(res!=b[i])mixx=a[i],pos=i,sum=sum1+a[i];
			else if(i+1<=n)mixx=a[i+1],pos=i+1,sum=sum1+a[i+1];
		}
	}
	sum1=sum;
	f[0]=d[0]=1;
	R int ret=0;
	for(R int i=n;i>=1;i--)
	{
		for(R int j=sum1;j>=1;j--)
		{
			if(j<a[i])break;
			if(!b[i]||(j-X>=a[i]))continue;
			sum2=max(sum2,j-X);
			for(R int num=1;num<=b[i];num++)
			{
				if(j-a[i]*num<0)break;
				if(j<=X)
				{
					tot++;
					f[j]+=f[j-a[i]*num];f[j]%=mod;
				}
				else
				{
					if(j-X>=a[i])continue;
					f[j]+=f[j-a[i]*num];f[j]%=mod;
				}
			}
		}
	}
	for(R int i=n;i>=1;i--)
	{
		for(R int j=sum2;j>=1;j--)
		{
			if(j<a[i])break;
			for(R int num=1;num<=c[i];num++)
			{
				tot++;
				if(j-a[i]*num<0)break;
				d[j]+=d[j-a[i]*num];d[j]%=mod;
			}
		}
	}
	ll ans=0;
	for(R int i=X;i<=50000;i++)
	{
		ans+=(f[i]*d[i-X]);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
