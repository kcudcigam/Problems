#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const int N=10000+7;
int tot=0,head[N],to[N<<1],nxt[N<<1];
I V add(R int x,R int y)
{
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
I V Add(R int x,R int y)
{
	add(x,y);add(y,x);
}
int n,m,ans=0,far1=0,depset=0;
bool v[N];
V dfs1(R int x,R int dep)
{
	v[x]=1;
	if(dep>depset)
	{
		depset=dep;far1=x;
	}
	for(R int i=head[x];i;i=nxt[i])
	{
		R int y=to[i];
		if(v[y])continue;
		dfs1(y,dep+1);
	}
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(R int i=1;i<=n-1;i++)
	{
		memset(v,0,sizeof(v));
		R int x=read(),y=read();
		depset=0;
		Add(x,y);
		far1=x;
		dfs1(x,0);
		
		memset(v,0,sizeof(v));
		depset=0;
		dfs1(far1,0);
		printf("%d\n",depset);
	}
	return 0;
}
