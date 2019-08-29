#include<bits/stdc++.h>
#define int long long
#define P 1000000007
using namespace std;
int a[1001],b[1001],c[1001];
int f[101][301][301];
int n,X;
int dfs(int dep,int change,int pay)
{
	if(dep>n)
	{
		if(pay-change==X)  return 1;
		return 0;
	}
	if(f[dep][change][pay]!=-1)  return f[dep][change][pay];
	int ans=dfs(dep+1,change,pay)%P;
	for(int i=1;i<=b[dep];i++)
	{
		if(pay+(i-1)*a[dep]>=X)  break;
		ans+=dfs(dep+1,change,pay+i*a[dep]);
		ans=ans%P;
	}
	for(int i=1;i<=c[dep];i++)
	{
		if(change+i*a[dep]>200)  break;
		ans+=dfs(dep+1,change+i*a[dep],pay);
		ans=ans%P;
	}
	f[dep][change][pay]=ans%P;
	return ans%P;
}
signed main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n>>X;
	for(int i=n;i>=1;i--)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	cout<<dfs(1,0,0)%P<<endl;
	return 0;
}
