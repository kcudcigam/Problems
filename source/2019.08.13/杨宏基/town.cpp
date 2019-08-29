#include<cstdio>
#include<iostream>
using namespace std;
int dad[100001],f[4001][4001],group1[100001],group2[100001],best[100001];
int n,t1,t2,mx;
int find(int x)
{
	return dad[x]=(dad[x]==x)?x:find(dad[x]);
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		dad[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		t1=t2=0;
		mx=max(best[find(x)],best[find(y)]);
		for(int j=1;j<=n;j++)
		{
			if(find(x)==find(j))
				group1[++t1]=j;
			if(find(y)==find(j))
				group2[++t2]=j;
		}
		for(int j=1;j<=t1;j++)
			for(int k=1;k<=t2;k++)
			{
				int u=group1[j],v=group2[k];
				f[u][v]=f[v][u]=f[u][x]+f[y][v]+1;
				mx=max(mx,f[u][v]);
			}
		dad[find(x)]=find(y);
		best[find(x)]=mx;
		printf("%d\n",mx);
	}
}
