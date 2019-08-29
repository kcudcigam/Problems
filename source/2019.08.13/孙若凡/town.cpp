#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(int x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void writeln(int x){ write(x),putchar('\n'); }
inline void File(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
}
const int N = 300005;
int To[N<<1],Ne[N<<1],He[N],_k = 0; inline void add(int x,int y){ ++_k; To[_k] = y,Ne[_k] = He[x],He[x] = _k; }
int n,ex[N],ey[N];
int dpt[N],fa[N],size[N],son[N],top[N];
inline void dfs1(int x){
	size[x] = 1,dpt[x] = dpt[fa[x]] + 1;
	for (int p = He[x],y; p ; p = Ne[p]) if ((y=To[p])^fa[x]){ fa[y] = x; dfs1(y); size[x] += size[y]; if (size[y] > size[son[x]]) son[x] = y; }
}
inline void dfs2(int x){
	if (son[x]){
		top[son[x]] = top[x],dfs2(son[x]);
		for (int p = He[x],y; p ; p = Ne[p]) if (!top[y=To[p]]) top[y] = y,dfs2(y);
	}
}
inline int Dis(int x,int y){
	static int ret; ret = dpt[x] + dpt[y];
	while (top[x] ^ top[y]){ if (dpt[top[x]] < dpt[top[y]]) swap(x,y); x = fa[top[x]]; }
	return ret - (min(dpt[x],dpt[y])<<1);
}
struct Union_Find_Set{
	int fa[N];
	int ex[N],ey[N],di[N];
	inline void init(int n){ for (int i = 1; i <= n; ++i) fa[i] = ex[i] = ey[i] = i,di[i] = 0; }
	inline int Find(int x){ return x == fa[x] ? x : fa[x] = Find(fa[x]); }
	inline int Query(int x){ return di[Find(x)]; }
	inline void Merge(int x,int y){
		static int a,b,c,d,t,ansx,ansy;
		x = Find(x),y = Find(y); fa[x] = y;
		a = ex[x],b = ey[x],ansx = c = ex[y],ansy = d = ey[y];
		if (di[x] > di[y]) di[y] = di[x],ansx = a,ansy = b;
		if ((t = Dis(a,c)) > di[y]) di[y] = t,ansx = a,ansy = c;
		if ((t = Dis(a,d)) > di[y]) di[y] = t,ansx = a,ansy = d;
		if ((t = Dis(b,c)) > di[y]) di[y] = t,ansx = b,ansy = c;
		if ((t = Dis(b,d)) > di[y]) di[y] = t,ansx = b,ansy = d;
		ex[y] = ansx,ey[y] = ansy;
	}
}S;
int main(){
	File();
	int i;
	n = read();
	for (i = 1; i < n; ++i) ex[i] = read(),ey[i] = read(),add(ex[i],ey[i]),add(ey[i],ex[i]);
	dfs1(1),top[1] = 1,dfs2(1);
	S.init(n); for (i = 1; i < n; ++i) S.Merge(ex[i],ey[i]),writeln(S.Query(ex[i])); return 0;
}
