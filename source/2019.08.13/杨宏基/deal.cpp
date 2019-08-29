#include<cstdio>
#include<iostream>
using namespace std;
int a[21],b[21],c[21],vis[21];
int n,x,cnt;
void dfs(int k,int s)
{
	if(k-1==2*n)
	{
		if(s!=x)
			return;
		cnt++;
		return;
	}
	if(k-1==n)
	{
		if(s<x)
			return;
		for(int i=1;i<=n&&a[i]<=s-x;i++)
			if(vis[i])
				return;
	}
	if(k<=n)
		for(int i=0;i<=b[k];i++)
		{
			if(s>=x&&i>0)
				break;
			vis[k]=i;
			dfs(k+1,s+i*a[k]);
			vis[k]=0;
		}
	else
		for(int i=0;i<=c[k-n];i++)
		{
			if(s<=x&&i>0)
				break;
			dfs(k+1,s-i*a[k-n]);
		}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	dfs(1,0);
	cout<<cnt;
}
