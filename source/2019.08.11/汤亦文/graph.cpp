#include<bits/stdc++.h>
using namespace std;
#define RG register int
#define M 10100
inline int qred()
{
	int s=0,w=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
queue<int>q;
int n,m,Q,tot;
int head[M],nex[M*2],edge[M*2],ver[M*2];
int d[M][M];
bool v[M];
inline void add(int x,int y,int z){ver[++tot]=y;edge[tot]=z;nex[tot]=head[x];head[x]=tot;}
inline void sss(int st)
{
	memset(v,0,sizeof(v));
	while(q.size()) q.pop();
	d[st][st]=0;v[st]=1;
	q.push(st);
	while(q.size())
	{
	int x=q.front();q.pop();
		v[x]=0;
		for(RG i=head[x];i;i=nex[i])
		{int y=ver[i],z=edge[i];
			if(d[x][st]<d[y][st]&&z<d[y][st])
			{
			 d[y][st]=max(d[x][st],z);
			 if(!v[y]) q.push(y),v[y]=1;
			}
		}
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int ans=-1;
	n=qred();m=qred();Q=qred();
	for(RG i=1;i<=m;i++)
	{
		int x=qred(),y=qred(),z=qred();
		add(x,y,z);
		add(y,x,z);
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) sss(i);
	for(RG i=1;i<=Q;i++)
	{int U=qred(),V=qred();
		if(d[U][V]==d[0][0]) printf("%d\n",ans);
		else printf("%d\n",d[U][V]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
