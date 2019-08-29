#include<bits/stdc++.h>
#define ll long long
#define R register
#define I inline
#define V void
using namespace std;
const int N=600000+7;
int tot=1,head[N],to[N<<1],nxt[N<<1];
I V add(R int x,R int y)
{
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
I V Add(R int x,R int y)
{
	add(x,y);add(y,x);
}
int h[N];
struct node
{
	int x,y,z;
}e[N+100];
I bool cmp(node a,node b)
{
	return a.z<b.z;
}
int find(R int x)
{
	return (h[x]==x?x:h[x]=find(h[x]));
}
int fa[N],now[N],dep[N],son[N],siz[N],top[N],pos[N];
int v[N];
V dfs1(R int x)
{
	siz[x]=1;
	for(R int i=head[x];i;i=nxt[i])
	{
		R int y=to[i];
		if(y==fa[x])continue;
		dep[y]=dep[x]+1,fa[y]=x;
		dfs1(y);
		siz[x]+=siz[y];
		son[x]=(siz[son[x]]>siz[y]?son[x]:y);
	}
}
V dfs2(R int x,R int tp)
{
	now[x]=++tot;
	pos[tot]=x;
	top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(R int i=head[x];i;i=nxt[i])
	{
		R int y=to[i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
#define ls rt<<1
#define rs rt<<1|1
int tr[N<<2];
I V up(R int rt)
{
	tr[rt]=max(tr[ls],tr[rs]);
}
V build(R int rt,R int l,R int r)
{
	if(l==r)
	{
		tr[rt]=v[pos[l]];
		return;
	}
	R int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	up(rt);
}
I int query(R int rt,R int l,R int r,R int LL,R int RR)
{
	if(LL<=l&&r<=RR)
	{
		return tr[rt];
	}
	R int mid=(l+r)>>1;
	R int ans=0;
	if(LL<=mid)ans=max(ans,query(ls,l,mid,LL,RR));
	if(RR>mid)ans=max(ans,query(rs,mid+1,r,LL,RR));
	return ans;
}
I V getans(R int x,R int y)
{
	R int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(1,1,tot,now[top[x]],now[x]));
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	ans=max(ans,query(1,1,tot,now[y],now[x]));
	printf("%d\n",ans);
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	R int n=0,m=0,Q=0;
	scanf("%d%d%d",&n,&m,&Q);
	for(R int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	sort(e+1,e+1+m,cmp);
	for(R int i=1;i<=n;i++)h[i]=i;
	R int ret=0;
	for(R int i=1;i<=m;i++)
	{
		R int fx=find(e[i].x),fy=find(e[i].y);
		if(fx==fy)continue;
		ret+=1;
		R int poss=n+ret;
		v[poss]=e[i].z;
		Add(e[i].x,poss);Add(poss,e[i].y);
		h[fx]=h[fy];
		if(ret==n-1)break;
	}
	tot=0;
	memset(dep,0,sizeof(dep));
	for(R int i=1;i<=n;i++)
	{
		if(!dep[i])
		{
			R int fx=find(i);
			dfs1(fx);dfs2(fx,fx);
		}
	}
	build(1,1,tot);
	for(R int i=1;i<=Q;i++)
	{
		R int x=0,y=0;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y))printf("-1\n");
		else getans(x,y);
	}
	return 0;
}

