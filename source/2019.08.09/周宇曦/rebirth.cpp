// luogu-judger-enable-o2
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
namespace dfuck{
	#define MAXN 0x7f
	#define MMAX 0x3f
	#define MINI 0x80
	#define DMINI 0xfe
	const int dmod1 = 193937, dmod2 = 193939;
	const int mod1 = 1e9+7, mod2 = 1e9+9, mod3 = 998244353;
	inline char gc(void)
	{
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}
	#define getchar() gc()
	template <typename T> inline void read(T &FF)
	{
		int RR = 1; FF = 0; char CH = getchar();
		for(; !isdigit(CH); CH = getchar()) if(CH == '-') RR = -RR;
		for(; isdigit(CH); CH = getchar()) FF = FF * 10 + CH - 48;
		FF *= RR;
	}
	template<typename T> inline void chkmax(T &a,T b) {a > b ? a = a : a = b;}
	template<typename T> inline void chkmin(T &a,T b) {a < b ? a = a : a = b;}
	inline void file(string str)
	{
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}
}
using namespace dfuck;
const int maxn = 2e5+10;
const int maxx = 500100;

vector <int> way[maxn];
int Num, n, m;
__gnu_pbds::priority_queue <long long, greater <long long> > hp[maxn],del[maxn];
long long dis[maxn], Ans[maxn];
int fa[maxn][30], dep[maxn], to[maxn];
int ui[maxx], vi[maxx], ki[maxx], flag[maxn], top[maxn], lst[maxn];
int now, fst[maxn], nxt[maxx << 1], num[maxx << 1], wi[maxx << 1];
struct point{
	int num;
	long long val;
	friend bool operator < (point a, point b){return a.val > b.val;}
};
inline void add(int u, int v, int w)
{
	nxt[++now] = fst[u], fst[u] = now, num[now] = v, wi[now] = w;
	nxt[++now] = fst[v], fst[v] = now, num[now] = u, wi[now] = w;
}
inline void Get_shortest()
{
	memset(dis, 0x7f, sizeof(dis));
	//for(int i = 1; i <= n; i++) dis[i] = LONG_LONG_MAX;
	dis[1] = 0;
	std::priority_queue <point> qi; qi.push((point){1, 0});
	while(!qi.empty())
	{
		point pi = qi.top(); qi.pop();
		if(flag[pi.num]) continue;
		flag[pi.num]=1;
		for(register int i = fst[pi.num]; i; i = nxt[i])
			if(pi.val + wi[i] < dis[num[i]])
				lst[num[i]] = pi.num, dis[num[i]] = pi.val + wi[i], qi.push((point){num[i], dis[num[i]]});
	}
}
inline void fst_dfs(int xi)
{
	dep[xi]=dep[fa[xi][0]]+1;
	for(register int i=1;i<=20;i++)
		fa[xi][i]=fa[fa[xi][i-1]][i-1];
	for(register int i = 0; i < way[xi].size(); i++)
		fa[way[xi][i]][0]=xi,fst_dfs(way[xi][i]);
}
inline int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (register int i = 20; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y) return x;
	for (register int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
inline void dfs(int xi)
{
	for(register int i = 0; i < way[xi].size(); i++)
	{
		dfs(way[xi][i]);
		hp[xi].join(hp[way[xi][i]]);
		del[xi].join(del[way[xi][i]]);
	}
	while(!hp[xi].empty() && !del[xi].empty() && hp[xi].top()==del[xi].top()) hp[xi].pop(), del[xi].pop();
	if(!hp[xi].empty()) Ans[xi] = hp[xi].top() - dis[xi];
	else Ans[xi] = -1;
}
signed main()
{
	file("rebirth");
	read(Num), read(n), read(m);
	for(register int i = 1; i <= m; i++)
	{
		read(ui[i]), read(vi[i]), read(ki[i]);
		add(ui[i], vi[i], ki[i]);
	}
	Get_shortest();
	for(register int i = 1; i <= n; i++)
		if(lst[i])
			way[lst[i]].push_back(i);
	top[1]=1,fst_dfs(1);
	for(register int i = 1; i <= m; i++)
	{
		if(lst[vi[i]] == ui[i] && !to[vi[i]] && dis[vi[i]] == dis[ui[i]] + ki[i]) to[vi[i]] = 1;
		else if(lst[ui[i]] == vi[i] && !to[ui[i]] && dis[ui[i]] == dis[vi[i]] + ki[i]) to[ui[i]] = 1;
		else
		{
			int fi=lca(vi[i], ui[i]);
			hp[ui[i]].push(dis[ui[i]] + dis[vi[i]] + ki[i]);
			hp[vi[i]].push(dis[ui[i]] + dis[vi[i]] + ki[i]);
			del[fi].push(dis[ui[i]] + dis[vi[i]] + ki[i]);
			del[fi].push(dis[ui[i]] + dis[vi[i]] + ki[i]);
		}
	}
	dfs(1); Ans[1] = 0;
	for(register int i = 1; i <= n; i++) printf("%lld ", Ans[i]);
	return 0;
}
