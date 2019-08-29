#include<cstdio>
int n,X,a[10010],b[10010],c[10010],ans;
void dfs1(int,int);
void dfs2(int,int);
void dfs1(int x,int m)
{
	if(x==n+1&&m<X) return ;
	if(m>X)
	{
		if(x>1&&m-X<=a[x-1]) return ;
		dfs2(1,m);
		return ;
	}
	for(int i=1;i<=b[x];i++) dfs1(x+1,m+i*a[x]);
	return ;
}
void dfs2(int x,int m)
{
	if(m<0) return ;
	if(m==0)
	{
		ans=(ans+1)%1000000007;
		return ;
	}
	for(int i=1;i<=c[x];i++) dfs2(x+1,m-i*a[x]);
	return ;
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&X);
	for(int i=0;i<n;i++) scanf("%d%d%d",&a[n-i],&b[n-i],&c[n-i]);
	dfs1(1,0);
	printf("%d\n",ans);
	return 0;
}
