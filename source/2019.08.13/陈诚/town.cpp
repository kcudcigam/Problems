#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> inline void rd(T &x)
{
	x=0; char ch=0; int f=1;
	for(;!isdigit(ch); ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48);return;}
	wrote(x/10);
	putchar(x%10+48);
}
struct node{
	int x,zz;
} nd[300005];
vector <int> g[300005];
bool vis[300005];
int n,a,b;
void dfs(int xx)
{
	vis[xx]=1;
	for(int i=0; i<g[xx].size(); ++i)
	{
		if(vis[xx]) continue;
		nd[g[xx][i]].x=nd[xx].x+1;
		nd[g[xx][i]].zz=nd[xx].zz;
	}
	vis[xx]=0;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	rd(n);
	for(int i=1; i<n; ++i)
	{
		rd(a); rd(b);	
		wrote(nd[a].x+nd[b].x+1);
		puts("");	
		if(nd[a].x<nd[b].x+1)
		{
			nd[a].x=nd[b].x+1; nd[a].zz=nd[b].zz; dfs(a);
		}
		if(nd[b].x<nd[a].x+1)
		{
			nd[b].x=nd[a].x+1; nd[b].zz=nd[a].zz; dfs(b);
		}
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	return 0;
}

