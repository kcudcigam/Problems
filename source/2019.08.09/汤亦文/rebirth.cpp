#include<bits/stdc++.h>
using namespace std;
#define RG register
#define M 100100
#define int long long
inline int read()
{
	long long s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
queue<int>q;
int d[M];
bool vi[M];
int ju,tot;
int ver[M],head[M],nex[M],edge[M];
int  numm,u,v,n,m,nu,qz,nuu;
inline void add(int x,int y,int z)
{
	ver[++tot]=y;edge[tot]=z;nex[tot]=head[x];head[x]=tot;
}
inline void spfa(int k)
{
	memset(vi,0,sizeof(vi));
	memset(d,0x3f,sizeof(d));
	ju=d[1];
	d[1]=0;vi[1]=1;
	while(q.size()) q.pop();
	q.push(1);
	while(q.size())
	{
		int x=q.front();q.pop();
		vi[x]=0;
		for(RG int i=head[x];i;i=nex[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
			 d[y]=d[x]+z;
			 if(y==k)
			 {
			 	u=x,v=y;
			 	qz=z;
			 	nu=i;
			 }
			if(!vi[y]) q.push(y),vi[y]=1;
			}
		}
	}
}
inline void spfaa()
{
	memset(vi,0,sizeof(vi));
	memset(d,0x3f,sizeof(d));
	d[1]=0;vi[1]=1;
	while(q.size()) q.pop();
	q.push(1);
	while(q.size())
	{
		int x=q.front();q.pop();
		vi[x]=0;
		for(RG int i=head[x];i;i=nex[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
			 d[y]=d[x]+z;
			if(!vi[y]) q.push(y),vi[y]=1;
			}
		}
	}
}
signed main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	numm=read();n=read();m=read();
	for(RG int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		if(x!=y)
		{
		add(x,y,z);
		add(y,x,z);
		}
	}
	cout<<"0"<<" ";
	for(RG int i=2;i<=n;i++)
	{
	u=v=0;nu=0,qz=0,nuu=0;
	spfa(i);
	for(RG int j=head[v];j;j=nex[j])
	{
		int uu=ver[j];
		if(uu==u)
		{
			nuu=j;
			edge[j]=ju;
		} 
	}
	edge[nu]=ju;
	spfaa();
	if(d[i]!=ju)
	cout<<d[i]<<" ";
	else cout<<"-1"<<" ";
	 edge[nu]=qz;edge[nuu]=qz;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
