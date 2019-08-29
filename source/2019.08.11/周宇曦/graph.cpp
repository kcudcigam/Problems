#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
#define maxn 300010
int n,m,q,tri;
int now,fst[maxn],nxt[maxn<<1],num[maxn<<1],wi[maxn<<1],ai[maxn];
int size[maxn],top[maxn],fa[maxn],son[maxn],seg[maxn],ki[maxn],dep[maxn],gs[maxn],sum;
void add(int u,int v,int w)
{
	nxt[++now]=fst[u],fst[u]=now,num[now]=v,wi[now]=w;
	nxt[++now]=fst[v],fst[v]=now,num[now]=u,wi[now]=w;
}
struct edge{
	int x,y,z;
	friend bool operator < (edge a,edge b){return a.z<b.z;}
}bn[maxn<<1];
int fi[maxn];
int bcj(int xi)
{
	if(fi[xi]==xi) return xi;
	return fi[xi]=bcj(fi[xi]);
}
int xds[(maxn<<2)+100];
void push_up(int pos)
{
	xds[pos]=max(xds[pos<<1],xds[pos<<1|1]);
}
void build(int pos,int l,int r)
{
	if(l==r)
	{
		xds[pos]=ai[ki[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	push_up(pos);
}
int Get_max(int pos,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr) return xds[pos];
	int mid=(l+r)>>1,res=0;
	if(mid>=ll) res=Get_max(pos<<1,l,mid,ll,rr);
	if(mid<rr) res=max(res,Get_max(pos<<1|1,mid+1,r,ll,rr));
	return res;
}
void fst_dfs(int xi,int G)
{
	size[xi]=1,dep[xi]=dep[fa[xi]]+1; gs[xi]=G;
	for(int i=fst[xi];i;i=nxt[i])
		if(num[i]!=fa[xi])
		{
			ai[num[i]]=wi[i],fa[num[i]]=xi,fst_dfs(num[i],G);
			size[xi]+=size[num[i]];
			if(size[num[i]]>size[son[xi]]) son[xi]=num[i];
		}
}
void nxt_dfs(int xi)
{
	if(son[xi])
	{
		top[son[xi]]=top[xi],seg[son[xi]]=++sum;
		ki[sum]=son[xi],nxt_dfs(son[xi]);
	}
	for(int i=fst[xi];i;i=nxt[i])
		if(!top[num[i]])
			top[num[i]]=num[i],seg[num[i]]=++sum,ki[sum]=num[i],nxt_dfs(num[i]);
}
int find_max(int xi,int yi)
{
	int ans=0;
	while(top[xi]!=top[yi])
	{
		if(dep[xi]<dep[yi]) swap(xi,yi);
		ans=max(ans,Get_max(1,1,n,seg[top[xi]],seg[xi]));
		xi=fa[top[xi]];
	}
	if(dep[xi]>dep[yi]) swap(xi,yi);
	ans=max(ans,Get_max(1,1,n,seg[xi],seg[yi]));
	return ans;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int X,Y;
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++)
		read(bn[i].x),read(bn[i].y),read(bn[i].z);
	sort(bn+1,bn+m+1);
	for(int i=1;i<=n;i++)
		fi[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(bcj(bn[i].x)==bcj(bn[i].y)) continue;
		add(bn[i].x,bn[i].y,bn[i].z),fi[bcj(bn[i].x)]=bcj(bn[i].y);
	}
	puts("1");
	for(int i=1;i<=n;i++)
		if(!gs[i])
			fst_dfs(i,++tri),top[i]=i,seg[i]=++sum,ki[sum]=i,nxt_dfs(i);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		read(X),read(Y);
		if(gs[X]!=gs[Y]) printf("-1\n");
		else printf("%d\n",find_max(X,Y));
	}
	return 0;
}

