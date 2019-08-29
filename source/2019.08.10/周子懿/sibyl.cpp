#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=100010;
int n,m,q;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f!='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
struct Arc
{
	Arc(int _u,int _v,int _w,int _next):
	u(_u),v(_v),w(_w),next(_next){}
	Arc(){}
	int u,v,w,next;
}e[N];
int head[N],size,ans[N],a[N],b[N],type[N];
void add(int u,int v,int w)
{
	e[++size]=Arc(u,v,w,head[u]);
	head[u]=size;
}
void MeM()
{
	memset(head,-1,sizeof(head));
}
void round(int u,int plus)
{
	ans[u]+=plus;
	for(int i=head[u];i!=-1;i=e[i].next)
	{
		ans[e[i].v]+=plus;
	}
}
void init()
{
	MeM();
	int x,y;
	read(n);read(m);read(q);
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);
		add(x,y,0);
		add(y,x,0);
	}
	for(int i=1;i<=q;i++)
	{
		read(type[i]);
		if(type[i]==1)
		{
			read(a[i]);read(b[i]);
		}else if(type[i]==0)
		{
			read(a[i]);
		}
	}
}
void work()
{
	for(int i=1;i<=q;i++)
	{
		if(type[i]==1)
		{
			round(a[i],b[i]);
		}else if(type[i]==0)
		{
			cout<<ans[a[i]]<<endl;
		}
	}
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	init();
	work();
	return 0;
}


