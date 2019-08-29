#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read(){
	static LL x; x = 0; static bool f; f = 0; static char c; c = getchar();
	while (!isdigit(c)){ if (c == '-') f = 1; c = getchar(); }
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return f ? -x : x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar('0'+x%10); }
inline void writeln(LL x){ write(x),putchar('\n'); }
inline void File(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
}
const int N = 500005;
vector<int>G[N];
int n,q,fa[N],vis[N]; LL val[N];
inline int Find(int x){ return x == fa[x] ? x : fa[x] = Find(fa[x]); }
inline void Merge(int x,int y){
	x = Find(x),y = Find(y);
	val[x] -= val[y],fa[x] = y,G[y].push_back(x);
}
inline void dfs(int x,int v){
	val[x] += v;
	vis[x] = 1;
	for (int i = 0; i < G[x].size(); ++i) dfs(G[x][i],val[x]);
}
int main(){
	File();
	int i,op,x,y;
	n = read(),q = read();
	for (i = 1; i <= n; ++i) fa[i] = i;
	while (q--){
		op = read();
		if (op == 1) x = read(),y = read(),Merge(x,y);
		else x = read(),x = Find(x),val[x] += read();
	}
	for (i = 1; i <= n; ++i) if (fa[i] == i && !vis[i]) dfs(i,0);
	for (i = 1; i <= n; ++i) write(val[i]),putchar(i < n ? ' ' : '\n');	
	return 0;
}
