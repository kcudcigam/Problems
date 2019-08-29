#include<bits/stdc++.h>
using namespace std;
int a[3000][3000];
int n,m,q;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		if(l<a[u][v]||a[u][v]==0)
		a[u][v]=a[v][u]=l;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	if(a[i][k]!=0&&a[k][j]!=0)
	a[i][j]=a[j][i]=min(a[i][j],max(a[i][k],a[k][j]));
	while(q--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",(a[u][v]==0 ? -1:a[u][v]));
	}
	return 0;
}

