#include<bits/stdc++.h>
#define gc() getchar()
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) (x<0?-x:x)
using namespace std;
template <typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
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
int a[N];
int q,opt,x,y;
void solve1()
{
	rep(i,1,q)
	{
		read(opt),read(x);
		if(opt==1)
		{
			read(y);
			a[x]+=y;
			for(int j=head[x];j;j=nex[j])
			a[to[j]]+=y;
		}
		else
		printf("%d\n",a[x]);
	}
}
bool f[N];
int sum,n;
void solve2()
{
	f[1]=1;
	for(int i=head[1];i;i=nex[i])
	f[to[i]]=1;
	rep(i,1,q)
	{
		read(opt),read(x);
		if(opt==1)
		{
			read(y);
			if(x==1)
			sum+=y;
			else
			{
				a[x]+=y;
				for(int j=head[x];j;j=nex[j])
				a[to[j]]+=y;
			}
		}
		else
		printf("%d\n",a[x]+(f[x]?sum:0));
	}
}
int du[N];
int mid[N],be[N],k;
int s[N];
void solve3()
{
	rep(i,1,n)
	if(du[i]>1)
	{
		mid[++k]=i;
		be[i]=k;
		for(int j=head[i];j;j=nex[j])
		be[to[j]]=k;
	}
	rep(i,1,q)
	{
		read(opt),read(x);
		if(opt==1)
		{
			read(y);
			if(x==mid[be[x]])
			s[be[x]]+=y;
			else a[mid[be[x]]]+=y,a[x]+=y;
		}
		else	printf("%d\n",s[be[x]]+a[x]);
	}
}
int m,u,v;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n),read(m),read(q);
	rep(i,1,m)
	{
		read(u),read(v);
		du[u]++;
		du[v]++;
		add(u,v);
		add(v,u);	
	}
	bool fla=1;
	rep(i,2,n)
	if(du[i]>10)
	fla=0;
	if(n<=3000&&m<=3000&&q<=3000)
	solve1();
	else
	if(fla)
	solve2();
	else solve3();
	return 0;
}


