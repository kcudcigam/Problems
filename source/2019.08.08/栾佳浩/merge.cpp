#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[10005];
int fa[10005];
inline int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=q;i++)
	{
		int typ;
		scanf("%d",&typ);
		if(typ==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int fx=find(x);
			int fy=find(y);
			if(fx==fy)continue;
			fa[fx]=fy;
		}
		else 
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int fx=find(x);
			for(int j=1;j<=n;j++)
			{
				if(find(j)==fx)a[j]+=y;
			}
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
}
