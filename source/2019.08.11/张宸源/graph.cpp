#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define gc() getchar()
using namespace std;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=300005;
int to[N<<1],nex[N<<1],w[N<<1],head[N],cnt;
void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nex[cnt]=head[x];
	head[x]=cnt;
}
int vis[N],dis[N],tur;
void dfs(int u,int len)
{
	if(vis[u]!=tur)
	dis[u]=len,vis[u]=tur;
	else
	{
		if(len>=dis[u])
		return;
		else dis[u]=len;
	}
	for(int i=head[u];i;i=nex[i])
	dfs(to[i],max(len,w[i]));
}
int n,m,q;
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n),read(m),read(q); 
	rep(i,1,m)
	{
		int u,v,w;
		read(u),read(v),read(w);
		add(u,v,w);
		add(v,u,w);
	}
	rep(i,1,q)
	{
		int x,y;
		read(x),read(y);
		memset(dis,0x3f,sizeof(dis));
		dis[i]=0;
		tur=i;
		dfs(x,0);
		if(vis[y]!=tur)
		puts("-1");
		else printf("%d\n",dis[y]);
	}
	return 0;
}



