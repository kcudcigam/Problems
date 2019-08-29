#include<bits/stdc++.h>
using namespace std;
#define RG register
#define M 300100
bool v[M];
int head[M],ver[M*2],nex[M*2],tot;
int ans,d[M];
inline void add(int a,int b)
{
	ver[++tot]=b;nex[tot]=head[a];head[a]=tot;
}
inline int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
inline void dd(int x)
{
	v[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int y=ver[i];
		if(v[y]) continue;
		dd(y);
		ans=max(ans,d[x]+d[y]+1);
		d[x]=max(d[x],d[y]+1);
	}
}
int n;
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b);
		add(b,a);
		ans=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		dd(a);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
