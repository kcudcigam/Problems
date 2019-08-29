#include<bits/stdc++.h>
using namespace std;
int Hash[10000005],ans,s,n,a[1000],b[1000],t,c[1000];
void check(int wz,int zh)
{
	Hash[zh]=1;
	if(wz==0)
	return ;
	for (int i=c[wz];i>-1;i--)
	{
		check(wz-1,zh+a[wz]*i);
	}
	return ;
}
void dfs(int wz,int zh)
{
	if(zh>=s)
	{
		if(Hash[zh-s]&&zh-s<a[wz+1])
		{
			ans++;
			ans%=1000000007;
		}
		return ;
	}
	if(wz==0)
	return ;
	for (int i=b[wz];i>-1;i--)
	{
		dfs(wz-1,zh+a[wz]*i);
	}
	return ;
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	ans=0;
	check(n,0);
	Hash[0]=1;
	dfs(n,0);
	cout<<ans<<endl;
	return 0;
}
