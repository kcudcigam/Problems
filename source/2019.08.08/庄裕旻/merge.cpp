#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000005;
template<typename T> inline void read(T &x)
{
	x=0; int t=0,f=1;
	while(t=getchar(),(t<'0'||t>'9')&&t!='-') t=getchar();
	if(t!='-') x=t-'0';
	else f=-1;
	while(t=getchar(),t>='0'&&t<='9') x=x*10+t-'0';
	x=x*f;
}
int n,m,f1[maxn],f2[maxn],b[maxn],res[maxn];
vector<int> G[maxn];
inline int ff(int u)
{
	int a=u,b;
	while(u!=f1[u]) u=f1[u];
	while(a!=u)
	{
		b=f1[a];
		f1[a]=u;
		a=b;
	}
	return u;
}
void dfs(int u,int x)
{
	x+=b[u];
	res[u]=x;
	for(int i=0;i<G[u].size();i++) dfs(G[u][i],x);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n); read(m);
	for(int i=1;i<=n;i++) f1[i]=i;
	int tot=n;
	for(int i=0;i<m;i++)
	{
		int op,x,y; read(op); read(x); read(y);
		if(op==1)
		{
			x=ff(x); y=ff(y);
			if(x!=y) { f1[x]=f1[y]=f2[x]=f2[y]=++tot; f1[tot]=tot; }
		}
		else
		{
			x=ff(x);
			b[x]+=y;
//			printf("b[%d]+=%d\n",x,y);
		}
	}
	for(int i=1;i<=tot;i++) G[f2[i]].push_back(i);
	dfs(0,0);
	for(int i=1;i<=n;i++) printf("%d ",res[i]); puts("");
	return 0;
}
/*
2 3
2 1 1
1 2 1
2 1 3
*/
