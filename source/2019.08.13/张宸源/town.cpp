#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define Rep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=300005;
int to[N<<1],head[N],nex[N<<1],cnt;
void add(int u,int v)
{
	to[++cnt]=v;
	nex[cnt]=head[u];
	head[u]=cnt;
}
int ans,x,n;
int dis[N];
int bfs(int u)
{
	queue<int> q;
	while(!q.empty())q.pop();
	q.push(u);
	memset(dis,0,sizeof(dis));
	int sum=0,c=u;
	int now;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(dis[now]>sum)
		sum=dis[now],c=now;
		for(int i=head[now];i;i=nex[i])
		if(dis[to[i]]==0&&to[i]!=u)
		dis[to[i]]=dis[now]+1,q.push(to[i]);
	}
	return c;
}
void solve1()
{
	rep(i,1,n-1)
	{
		int a,b;
		read(a),read(b);
		add(a,b),add(b,a);
		x=bfs(a);
		ans=bfs(x);
		printf("%d\n",dis[ans]);
	}
}
int far[N];
void solve2()
{
	far[1]=1;
	dis[1]=0; 
	rep(i,1,n-1)
	{
		int a,b;
		read(a),read(b);
		far[b]=far[a];
		dis[b]=dis[a]+1;
		if(dis[far[a]]<dis[b])
		dis[far[a]]=dis[b],far[far[a]]=b;
		ans=max(ans,dis[b]);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	if(n<=2000)
	solve1();
	else solve2();
	return 0;
}



