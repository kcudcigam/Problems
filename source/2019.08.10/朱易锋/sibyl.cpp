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
const int N=300000+107;
int head[N],nxt[N<<1],to[N<<1],tot=1;
I V add(R int x,R int y)
{
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
I V Add(R int x,R int y)
{
	add(x,y);add(y,x);
}
int tag[N],ans[N];
I V down(R int x)
{
	ans[x]+=tag[x];
	for(R int i=head[x];i;i=nxt[i])
	{
		R int y=to[i];
		ans[y]+=tag[x];
	}
	tag[x]=0;
}
I int getans(R int x)
{
	if(tag[x])down(x);
	for(R int i=head[x];i;i=nxt[i])
	{
		R int y=to[i];
		if(!tag[y])continue;
		else down(y);
	}
	return ans[x];
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	R int n=0,m=0,Q=0;
	scanf("%d%d%d",&n,&m,&Q);
	for(R int i=1;i<=m;i++)
	{
		R int x=0,y=0;
		scanf("%d%d",&x,&y);
		Add(x,y);
	}
	for(R int i=1;i<=Q;i++)
	{
		R int opt=0,x=0;
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			R int val=0;
			scanf("%d",&val);
			tag[x]+=val;
		}
		else
		{
			printf("%d\n",getans(x));
		}
	}
	return 0;
}
