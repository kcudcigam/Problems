#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename T> inline void rd(T &x)
{
	x=0; int f=1; char ch=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
vector < pair<int,int> > g[300003];
int x,y,z,ans,vis[300003],n,m,Q;
void dfs(int x,int cnt)
{
	if(x==y)
	{
		ans=min(ans,cnt);
		return;
	}
	vis[x]=1;
	for(int i=0; i<g[x].size(); ++i)
	{
		if(!vis[g[x][i].first])
		{
			dfs(g[x][i].first,max(cnt,g[x][i].second));
		}
	}
	vis[x]=0;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	rd(n); rd(m); rd(Q);
	for(int i=1; i<=n; ++i)
	{
		rd(x); rd(y); rd(z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	for(int i=1; i<=Q; ++i)
	{
		ans=2147483647;
		rd(x); rd(y);
		dfs(x,0);
		if(ans==2147483647) ans=-1;
		wrote(ans);
		puts("");
	}
	return 0;
}

