#include<bits/stdc++.h>
using namespace std;
#define int long long
#define RG register
#define M 300100
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int n,m,q,tot;
bool ins[M],vis[M],jud;
int s[M],ttt;
int ver[M*2],head[M],nex[M*2],edge[M],d[M];
int bel[M],edg[M];
inline void add(int x,int y)
{
	ver[++tot]=y;nex[tot]=head[x];head[x]=tot;d[y]++;
	if(d[y]>1&&!ins[y])
	{
		ins[y]=1;
		s[++ttt]=y;
	} 
}
signed main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();m=read();q=read();
	for(int RG i=1;i<=m;i++) 
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(RG int i=1;i<=ttt;i++)
	{
		if(vis[s[i]])
		{
			jud=1;break;
		}
		vis[s[i]]=1;
		bel[i]=i;
	  for(RG int j=head[s[i]];j;j=nex[j])
	  {
	  	if(vis[ver[j]])
	  	{
	  		jud=1;break;
		}
		vis[ver[j]]=1;
		bel[ver[j]]=i;
	  }
	}
	if(!jud)
	{
		for(RG int i=1;i<=q;i++)
	 {
		int t=read(),x=read();
		if(t)
		{
			int k=read();
			if(bel[x]==x)
			{
				edg[x]+=k;
			}
			else if(vis[x])
			{
				edge[x]+=k;
				edge[bel[x]]+=k;
			}
			else
			{
			for(RG int j=head[x];j;j=nex[j])
			  edge[ver[j]]+=k;
			edge[x]+=k;
			}
		}
		else
		{
			int aans=edge[x]+edg[bel[x]];
			cout<<aans<<endl;
		}
	 }
	}
	else
	{
	   for(RG int i=1;i<=q;i++)
	 {
		int t=read(),x=read();
		if(t)
		{
			int k=read();
			for(RG int j=head[x];j;j=nex[j])
			edge[ver[j]]+=k;
			edge[x]+=k;
		}
		else
		{
			cout<<edge[x]<<endl;
		}
	 }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
