#include<bits/stdc++.h>
#define maxn 300010
#define inf 0x3f3f3f3f
using namespace std;
int n,m,q,tot;
int cnt;
int a[maxn<<1][3],b[maxn];
int v[maxn],vis[maxn];
inline void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void add(int x,int y)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=b[x];
	b[x]=tot;
	tot++;
	a[tot][0]=y;
	a[tot][1]=x;
	a[tot][2]=b[y];
	b[y]=tot;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	fread(n),fread(m),fread(q);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		fread(x),fread(y);
		add(x,y);
		if(x==1) vis[y]=true;
		if(y==1) vis[x]=true;
	}
	for(int i=1;i<=q;i++)
	{
		int tp;
		fread(tp);
		if(tp==0)
		{
			int x,ans;
			fread(x);
			ans=v[x];
			if(vis[x]) ans+=cnt;
			printf("%d\n",ans);
		}
		else
		{
			int x,y;
			fread(x),fread(y);
			v[x]+=y;
			if(x==1) cnt+=y;
			else
			{
				for(int i=b[x];i;i=a[i][2])
				v[a[i][1]]+=y;
			}
		}
	}
	return 0;
}


