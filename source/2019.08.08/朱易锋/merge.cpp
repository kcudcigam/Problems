#include<bits/stdc++.h>
#define I inline
#define R register
#define V void
#define ll long long
using namespace std;
template <typename T> void read(T &x)
{
	ll f=1;x=0;R char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=1000000+7;
int head[N],next[N<<1],to[N<<1],tot=0;
I V add(R int x,R int y)
{
	next[++tot]=head[x],head[x]=tot,to[tot]=y;
}
int h[N],s[N],ans[N],fa[N];
int find(R int x)
{
	return ((h[x]==x)?x:h[x]=find(h[x]));
}
bool v[N];
V dfs(R int x)
{
	ans[x]=ans[fa[x]]+s[x];
	for(R int i=head[x];i;i=next[i])
	{
		R int y=to[i];
		if(y==fa[x])continue;
		fa[y]=x;
		dfs(y);
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	R int n=0,m=0;
	read(n);read(m);
	for(R int i=1;i<=n;i++)h[i]=i;
	R int pos=n;
	for(R int i=1;i<=m;i++)
	{
		R int opt=0,x=0,y=0;
		read(opt);read(x);read(y);
		if(opt==2)
		{
			R int fx=find(x);
			s[fx]+=y;
		}
		else
		{
			R int fx=find(x),fy=find(y);
			if(fx==fy)continue;
			pos++;h[pos]=pos;
			add(pos,fx);add(pos,fy);
			h[fx]=pos;h[fy]=pos;
		}
	}
	for(R int i=1;i<=n;i++)
	{
		R int fx=find(i);
		if(v[fx])continue;v[fx]=1;
		dfs(fx);
	}
	for(R int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
