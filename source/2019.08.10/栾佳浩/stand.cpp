#include<bits/stdc++.h>
using namespace std;
int n,m;
int l[55],r[55],cov[55];
int b[55];
long long x1,x2,x3,x4,x5;
long long mxx;
long long calc(int i)
{
	return x1*i+x2*i*i+x3*i*i*i+x4*i*i*i*i+x5*i*i*i*i*i;
}
void dfs(long long ans,int stp)
{
		int maxx=-1;
		for(int i=1;i<=m;i++)
		if(cov[i]>maxx)
		{
			maxx=cov[i];
		}
		if(maxx==0)
		{
			mxx=max(mxx,ans);
			return ;
		}
		for(int i=1;i<=m;i++)
		{
			if(cov[i]==maxx)
			{
				for(int j=1;j<=n;j++)
				{
					if(!b[j]&&l[j]<=i&&r[j]>=i)
					{
						b[j]=stp;
						for(int k=l[j];k<=r[j];k++)cov[k]--;
					}
				}
				dfs(ans+calc(maxx),stp+1);
				for(int j=1;j<=n;j++)
				{
					if(b[j]==stp)
					{
						b[j]=0;
						for(int k=l[j];k<=r[j];k++)cov[k]++;
					}
				}
			}
		}
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout); 
	scanf("%d%d",&n,&m);
	int flag=1;
	scanf("%lld%lld%lld%lld%lld",&x1,&x2,&x3,&x4,&x5);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]!=1||r[i]!=m)flag=0;
		for(int j=l[i];j<=r[i];j++)
		cov[j]++;
	}
	if(flag)
	{
		printf("%lld",calc(n));
		return 0;
	}
	dfs(0,1);		
	printf("%lld",mxx);
}
