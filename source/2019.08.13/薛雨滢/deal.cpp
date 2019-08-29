#include<bits/stdc++.h>

using namespace std;
const int mod=1000000007;
const int MAXN=1005;

int n,x;
int a[MAXN],b[MAXN],c[MAXN],ccnt;
int kee[MAXN*10],ans;
int dp1[20005],dp2[20005],maxn;

void dfs(int num,int cnt,int minn)
{
	if(num==n+1&&cnt-x<minn) {dp1[cnt]++;maxn=max(cnt,maxn);return ;};
	for(int i=0;i<b[num];i++)
	{
		if(cnt+a[num]*i-x>=min(minn,a[num])) return ;
		dfs(num+1,cnt+a[num]*i,min(minn,a[num]));
	}
	dfs(num+1,cnt+a[num]*b[num],minn);
}

int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		int tem=1;
		while(c[i]>=tem)
		{
			kee[++ccnt]=a[i]*tem;
			c[i]-=tem;
			tem<<=1;
		}
		if(c[i]) kee[++ccnt]=a[i]*c[i];
	}
	
	dfs(1,0,0x3f3f3f3f);
	dp2[0]=1;
	for(int i=1;i<=ccnt;i++)
	{
		for(int j=maxn-x;j>=kee[i];j--)
		dp2[j]+=dp2[j-kee[i]];
	}
	
	for(int i=x;i<=maxn;i++) 
	{
		ans=(ans+(dp1[i]*dp2[i-x])%mod)%mod;
	}
	
	cout<<ans<<endl;
	return 0;
 } 
