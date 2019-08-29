#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;char c;bool f=0;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);return *this;
	}
}yin;
const unsigned int maxn=3*1e5+1000;
struct edge{
	int v,nxt;
}e[maxn<<1];
unsigned int in[maxn],tot,head[maxn],dd[maxn],sum[maxn],ad[maxn];
void __ADD(int u,int v)
{
	++in[v];
	e[++tot].v=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
void add(int u,int v)
{
	__ADD(u,v);
	__ADD(v,u);
}
list<int> a[maxn];
list<int>::iterator xxx[maxn];
int main()
{
	fre("sibyl");
	register unsigned int n,m,q;
	yin>>n>>m>>q;
	
	if(n<=3000&&q<=3000)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			yin>>x>>y;
			add(x,y);
		}
		while(q--)
		{
			int t,x,y;
			yin>>t;
			if(t)
			{
				yin>>x>>y;
				sum[x]+=y;
				for(int i=head[x];i;i=e[i].nxt)
				{
					sum[e[i].v]+=y;
				}
			}
			else
			{
				yin>>x;
				printf("%d\n",sum[x]);
			}
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		yin>>x>>y;
		add(x,y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bool f=0;
	for(int i=2;i<=n;i++)
	{
		if(in[i]>10){f=1;break;}
	}
	if(!f)
	{
		for(int i=head[1];i;i=e[i].nxt){
			dd[e[i].v]=1;
		}
		int xxxxx=0;
		while(q--)
		{
			int t,x,y;
			yin>>t;
			if(t)
			{
				yin>>x>>y;
				sum[x]+=y;
				if(x==1){xxxxx+=y;continue;}
				for(int i=head[x];i;i=e[i].nxt)
				{
					sum[e[i].v]+=y;
				}
			}
			else
			{
				yin>>x;
				if(dd[x])
				{
					printf("%d\n",sum[x]+xxxxx);
				}else
				printf("%d\n",sum[x]);
			}
		}
		return 0;
	}
	for(register unsigned int i=1;i<=n;i++)
	{
		if(in[i]<=100)dd[i]=1;
	}
	for(register unsigned int i=1;i<=n;i++)
	{
		register unsigned int tot=0;
		for(list<int>::iterator j=a[i].begin();j!=a[i].end();j++)
		{
			xxx[++tot]=j;
		}
		for(register unsigned int i=1;i<=tot;i++)a[i].erase(xxx[i]);
	}
	while(q--)
	{
		register unsigned int t,x,y;
		yin>>t;
		if(t)
		{
			yin>>x>>y;
			ad[x]+=y;
			sum[x]+=y;
			for(list<int>::iterator i=a[x].begin();i!=a[x].end();i++)
			{
				sum[*i]+=y;
				cout<<in[*i]<<endl;
			}
		}
		else
		{
			yin>>x;
			if(dd[x])
			{
				register unsigned int ans=0;
				for(register unsigned int i=head[x];i;i=e[i].nxt)
				{
					ans+=ad[e[i].v];
				}
				printf("%d\n",ans+ad[x]);
			}
			else
			{
				printf("%d\n",sum[x]);
			}
		}
	}
	return 0;
}
