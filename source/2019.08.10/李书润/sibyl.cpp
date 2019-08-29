#include<bits/stdc++.h>
using namespace std;
int target[600001],pre[600001],last[600001],tot,ans[300001];
bool con[300001];
void add(int x,int y)
{
	tot++;
	target[tot]=y;
	pre[tot]=last[x];
	last[x]=tot;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q,x,y,op;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		add(x,y);
		add(y,x);
		if(x==1&&y!=1)con[y]=1;
	}
	int delta=0;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			ans[x]+=y;
			if(x==1)delta+=y;
			else for(int j=last[x];j;j=pre[j])ans[target[j]]+=y;
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",con[x]?delta+ans[x]:ans[x]);
		}
	}
	return 0;
}
