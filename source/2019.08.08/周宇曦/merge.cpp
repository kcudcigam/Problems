#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
int sum[500100],fa[500100],tag[500100];
int fst[500100],nxt[1000010],num[1000010],now;
void add(int u,int v)
{
	nxt[++now]=fst[u],fst[u]=now,num[now]=v;
}
int bcj(int xi)
{
	if(fa[xi]==xi) return xi;
	fa[xi]=bcj(fa[xi]);
	return fa[xi];
}
void dfs(int xi,int tagi)
{
	tagi+=tag[xi];
	sum[xi]+=tagi;
	for(int i=fst[xi];i;i=nxt[i])
		dfs(num[i],tagi);
	tag[xi]=0;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,op;
	read(n),read(q);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=q;i++)
	{
		read(op);
		int x,y;
		read(x),read(y);
		if(op==1)
		{
			if(bcj(x)!=bcj(y))
				tag[bcj(x)]-=tag[bcj(y)],add(bcj(y),bcj(x)),fa[bcj(x)]=bcj(y);
		}
		else tag[bcj(x)]+=y;
	}
	for(int i=1;i<=n;i++)
		if(bcj(i)==i)
			dfs(i,0);
	for(int i=1;i<=n;i++)
		printf("%d ",sum[i]);
	return 0;
}

