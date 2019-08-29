#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
int fst[300010],nxt[600010],num[600010],now,dep[300010];
void add(int u,int v)
{
	nxt[++now]=fst[u],fst[u]=now,num[now]=v;
	nxt[++now]=fst[v],fst[v]=now,num[now]=u;
}
int dad[300010];
void make_dep(int xi,int fa)
{
	dep[xi]=dep[fa]+1; dad[xi]=fa;
	for(int i=fst[xi];i;i=nxt[i])
		if(num[i]!=fa)
			make_dep(num[i],xi);
}
int fi[300010];
int bcj(int xi)
{
	if(fi[xi]==xi) return xi;
	return fi[xi]=bcj(fi[xi]);
}
int ans;
int zj[300010];
int ui[300010],vi[300010];
int dis[300010],dn[300010];
void make_dp(int xi)
{
	for(int i=fst[xi];i;i=nxt[i])
	{
		if(num[i]==dad[xi]) continue;
		if(dis[num[i]]+1>dis[xi]) dis[xi]=dis[num[i]]+1;
		else if(dis[num[i]]+1>dn[xi]) dn[xi]=dis[num[i]]+1;
	}
	ans=max(ans,dis[xi]+dn[xi]);
	if(bcj(xi)!=xi) make_dp(dad[xi]); 
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n,u,v;
	read(n);
	for(int i=1;i<=n-1;i++)
		read(u),read(v),add(u,v),ui[i]=u,vi[i]=v;
	make_dep(1,0);
	for(int i=1;i<=n;i++)
		fi[i]=i;
	memset(fst,0,sizeof(fst)),memset(nxt,0,sizeof(nxt)),memset(num,0,sizeof(num)),now=0;
	for(int i=1;i<=n-1;i++)
	{
		add(ui[i],vi[i]);
		if(dep[bcj(ui[i])]>dep[bcj(vi[i])]) swap(ui[i],vi[i]);
		ans=0;
		ans=max(zj[bcj(ui[i])],zj[bcj(vi[i])]);
		make_dp(ui[i]);
		dad[bcj(vi[i])]=bcj(ui[i]);
		zj[bcj(ui[i])]=ans;
		printf("%d\n",ans);
	}
	return 0;
}



