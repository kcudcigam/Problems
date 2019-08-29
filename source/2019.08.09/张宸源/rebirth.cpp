#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define gc() getchar()
#define il inline
#define ll long long
#define pb push_back
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
template<typename T>il void read(T&x)
{
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=gc())if(c=='-')f=-f;
	for(;isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int N=200005;
vector<int> a[N],c[N],d[N];
ll ans[N],dis[N];
int ex,ey,ex1,ey1;
bool vis[N];
void dfs(int u,ll di)
{
	if(di>=dis[u])
	return;
	dis[u]=di;
	vis[u]=1;
	rep(i,0,a[u].size()-1)
	{
		if(!((u==ex&&i==ey)||(u==ex1&&i==ey1)))
		dfs(a[u][i],di+c[u][i]);
	}
}
int num,n,m,x,y,z;
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(num),read(n),read(m);
	rep(i,1,m)
	{
		read(x),read(y),read(z),a[x].pb(y),a[y].pb(x),c[x].pb(z),c[y].pb(z);
		d[x].pb(a[y].size()-1),d[y].pb(a[x].size()-1);
	}
	printf("0");
	rep(i,1,n)
	rep(j,0,a[i].size()-1)
	{
		rep(k,1,n)
		dis[k]=lnf,vis[k]=0;
		ex=i,ey=j;
		ex1=a[i][j],ey1=d[i][j];
		dfs(1,0);
		if(!vis[i])
		ans[i]=-1;
		if(ans[i]!=-1)
		ans[i]=max(ans[i],dis[i]);
		if(!vis[a[i][j]])
		ans[a[i][j]]=-1;
		if(ans[a[i][j]]!=-1)
		ans[a[i][j]]=max(ans[a[i][j]],dis[a[i][j]]);
	}
	rep(i,2,n)printf(" %d",ans[i]);
	return 0;
}

