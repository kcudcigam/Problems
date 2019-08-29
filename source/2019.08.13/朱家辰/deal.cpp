#include<bits/stdc++.h>
#define maxn 1010
#define maxm 20010
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll f[2][maxm],g[2][maxm],ans,a[maxn],b[maxn],c[maxn],x,y,n;
void fread(ll &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	fread(n),fread(x);
	ll s=0;
	for(int i=n;i>=1;i--)
	{
		fread(a[i]),fread(b[i]),fread(c[i]);
		s=max(s,a[i]);
	}
	y=x+s-1;
	f[0][0]=1;
	int now1=1,now2=1,pre1=0,pre2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=x+a[i];j<=y;j++) f[now1][j]=f[pre1][j];
		for(int r=0;r<a[i];r++)
		{
			ll sum=0;
			for(int tmp=r;tmp<=y&&a[i]>tmp-x;tmp+=a[i])
			{
				sum=(sum+f[pre1][tmp])%mod;
				f[now1][tmp]=sum;
				if(tmp>=b[i]*a[i])
				sum=(sum-f[pre1][tmp-b[i]*a[i]]+mod)%mod;
			}
		}
		now1^=1;
		pre1^=1;
	}
	g[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int r=0;r<a[i];r++)
		{
			ll sum=0;
			for(int tmp=r;tmp<=y-x;tmp+=a[i])
			{
				sum=(sum+g[pre2][tmp])%mod;
				g[now2][tmp]=sum;
				if(tmp>=c[i]*a[i])
				sum=(sum-g[pre2][tmp-c[i]*a[i]]+mod)%mod;
			}
		}
		now2^=1;
		pre2^=1;
	}
	int k=n;
	for(int i=x;i<=y;i++)
	{
		while(a[k]<=i-x&&k>0) k--;
		if(k==0) break;
		ans=(ans+(f[pre1][i]*g[pre2][i-x])%mod)%mod;
	}
	printf("%d",ans);
	return 0;
}


