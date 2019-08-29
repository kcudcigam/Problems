#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar(); F*=R;
}
int now,fst[300010],nxt[600010],num[600010];
int Now,Fst[300010],Nxt[600010],Num[600010];
int rd[300010],sum[300010],tag[300010];
struct bian{
	int ai,bi;
	friend bool operator < (bian ax,bian bx)
	{
		return (ax.ai==bx.ai)?ax.bi<bx.bi:ax.ai<bx.ai;
	} 
}Bn[600010];
int jh;
void add(int u,int v)
{
	nxt[++now]=fst[u],fst[u]=now,num[now]=v;
	nxt[++now]=fst[v],fst[v]=now,num[now]=u;
}
void Add(int u,int v)
{
	Nxt[++Now]=Fst[u],Fst[u]=Now,Num[Now]=v;
}
int Sum(int x)
{
	int ansi=0;
	for(int i=Fst[x];i;i=Nxt[i])	
		ansi+=tag[Num[i]];
	return ansi;
}
void anum(int x,int y)
{
	sum[x]+=y;
	for(int i=Fst[x];i;i=Nxt[i])
		sum[Num[i]]+=y;
	tag[x]+=y;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q,op,x,y,u,v;
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++)
	{
		read(u),read(v);
		if(u!=v) Bn[++jh].ai=u,Bn[jh].bi=v;
	}
	sort(Bn+1,Bn+jh+1);
	for(int i=1;i<=jh;i++)
	{
		if(!(Bn[i].ai==Bn[i-1].ai&&Bn[i].bi==Bn[i-1].bi))
			add(Bn[i].ai,Bn[i].bi),rd[Bn[i].ai]++,rd[Bn[i].bi]++;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=fst[k];i;i=nxt[i])
		{
			if(num[i]<k) continue;
			if(rd[k]>rd[num[i]]) Add(num[i],k);
			else Add(k,num[i]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		read(op);
		if(!op) read(x),printf("%d\n",sum[x]+Sum(x));
		else read(x),read(y),anum(x,y);
	}
	return 0;
}

