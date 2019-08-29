#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int x,y,fs,nx;
}e[1000001];
int vis[1000001],cnt[1000001];
int n,m,q,x,y,type,p;
void build(int u,int v)
{
	e[++p]=(node){u,v,e[p].fs,e[u].fs};
	e[u].fs=p;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		build(x,y);
		build(y,x);
	}
	while(q--)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d%d",&x,&y);
			cnt[x]+=y;
			vis[x]=1;
			for(int i=e[x].fs;i;i=e[i].nx)
				if(!vis[e[i].y])
				{
					vis[e[i].y]=1;
					cnt[e[i].y]+=y;
				}
			memset(vis,0,sizeof(vis));
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",cnt[x]);
		}
	}
}
