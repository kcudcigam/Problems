#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void writeln(LL x){ write(x),putchar('\n'); }
inline void File(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
}
const int N = 200005,M = 500005; const LL INF = 1LL<<62;
struct Node{ int x; LL d; bool operator < (Node w) const{ return d > w.d; } }t; priority_queue<Node>H;
int Num,n,m,ex[M],ey[M],ez[M],inT[M]; LL dis[N];

int deg[N],To[M<<1],Ne[M<<1],Dis[M<<1],He[N],_k = 1;
inline void add(int x,int y,int z){ ++_k; To[_k] = y,Ne[_k] = He[x],Dis[_k] = z,He[x] = _k; ++_k; To[_k] = x,Ne[_k] = He[y],Dis[_k] = z,He[y] = _k; }

struct Union_Find_Set{
	int fa[N];
	inline void init(int n){ for (int i = 1; i <= n; ++i) fa[i] = i; }
	inline int Find(int x){ return x == fa[x] ? x : fa[x] = Find(fa[x]); }
	inline void Merge(int x,int y){ fa[Find(x)] = Find(y); }
	inline bool unLinked(int x,int y){ return Find(x) ^ Find(y); }
}S;

LL Tdis[N],ans[N]; int fa[N],tl[N],tr[N],Time,vis[N];
inline void build_T(int x){
	tl[x] = ++Time; for (int y,p = He[x]; p ; p = Ne[p]) if ((y = To[p]) ^ fa[x]) fa[y] = x,Tdis[y] = Tdis[x] + Dis[p],build_T(y); tr[x] = Time;
}

const int NN = N * 60;
LL mn[NN],tag[NN]; int lc[NN],rc[NN],cnt_node; int st[NN],top;

int ll,rr,pp; LL vv,qans;
inline void Down(int o){
	if (tag[o]){
		if (lc[o]){
			tag[lc[o]] += tag[o]; mn[lc[o]] += tag[o]; if (mn[lc[o]] > INF) mn[lc[o]] = INF;
		}
		if (rc[o]){
			tag[rc[o]] += tag[o]; mn[rc[o]] += tag[o]; if (mn[rc[o]] > INF) mn[rc[o]] = INF;
		}
		tag[o] = 0;
	}
}
inline void Modify(int &o,int l,int r){
	if (!o) o = top ? st[top--] : ++cnt_node,mn[o] = INF,lc[o] = rc[o] = tag[o] = 0;
	else tag[o] += vv,mn[o] += vv,Down(o);
}
inline void Add(int &o,int l,int r){
	if (!o) o = top ? st[top--] : ++cnt_node,mn[o] = INF,lc[o] = rc[o] = tag[o] = 0;
	if (l == r) mn[o] = min(mn[o],vv);
	else{
		Down(o);
		int mid = l + r >> 1; if (pp <= mid) Add(lc[o],l,mid); else Add(rc[o],mid+1,r);
		mn[o] = INF;
		if (lc[o]) mn[o] = min(mn[o],mn[lc[o]]);
		if (rc[o]) mn[o] = min(mn[o],mn[rc[o]]);
	}
}
inline void Query(int o,int l,int r){
	if (!o) return;
	if (ll <= l && rr >= r) qans = min(qans,mn[o]);
	else{ Down(o); int mid = l + r >> 1; if (ll <= mid) Query(lc[o],l,mid); if (rr > mid) Query(rc[o],mid+1,r); }
}
inline int Merge(int x,int y,int l,int r){
	if (!x || !y) return x|y;
	else if (l == r) {mn[x] = min(mn[x],mn[y]),st[++top] = y; return x;}
	else{
		Down(x),Down(y);
		int mid = l + r >> 1;
		mn[x] = min(mn[x],mn[y]); 
		lc[x] = Merge(lc[x],lc[y],l,mid),rc[x] = Merge(rc[x],rc[y],mid+1,r);
		st[++top] = y; return x;
	}
}

int T[N];
inline void dfs_ans(int x){
	for (int y,p = He[x]; p ; p = Ne[p]) if ((y = To[p]) ^ fa[x]){
		dfs_ans(y);
		vv = Dis[p]; Modify(T[y],1,n);
		T[x] = Merge(T[x],T[y],1,n);
	}
	qans = INF;
	if (tl[x] > 1) ll = 1,rr = tl[x] - 1,Query(T[x],1,n);
	if (tr[x] < n) ll = tr[x] + 1,rr = n,Query(T[x],1,n);
	ans[x] = min(ans[x],qans); if (ans[x] < INF) vis[x] = 1;
}
int main(){
	File();
	int i,x,y,p;
	Num = read();
	n = read(),m = read();
	_k = 1,memset(He,0,sizeof(He));
	for (i = 1; i <= m; ++i) ex[i] = read(),ey[i] = read(),ez[i] = read(),inT[i] = 0,add(ex[i],ey[i],ez[i]),++deg[ex[i]],++deg[ey[i]];
	dis[1] = 0; for (i = 2; i <= n; ++i) dis[i] = INF; t.x = 1,t.d = 0,H.push(t);
	while (!H.empty()){
		t = H.top(); H.pop(); if (t.d > dis[x=t.x]) continue;
		for (p = He[x]; p ; p = Ne[p]) if (dis[y = To[p]] > dis[x] + Dis[p]){ dis[y] = dis[x] + Dis[p]; t.x = y,t.d = dis[y]; H.push(t); }
	}
	
	S.init(n); _k = 1,memset(He,0,sizeof(He));
	
	for (i = 1; i <= m; ++i) if (S.unLinked(ex[i],ey[i]) && (dis[ex[i]] + ez[i] == dis[ey[i]] || dis[ey[i]] + ez[i] == dis[ex[i]])) S.Merge(ex[i],ey[i]),add(ex[i],ey[i],ez[i]),inT[i] = 1;
	
	fa[1] = Tdis[1] = 0,build_T(1); top = 0,cnt_node = 0;
	for (i = 1; i <= n; ++i) ans[i] = INF,vis[i] = 0,T[i] = 0;
	for (i = 1; i <= m; ++i) if (!inT[i]){
		x = ex[i],y = ey[i];
		if (tl[y] < tl[x] || tl[y] > tr[x]){
			vis[x] = 1,ans[x] = min(ans[x],Tdis[y] + ez[i]);
			pp = tl[y],vv = Tdis[y] + ez[i],Add(T[x],1,n);
		}
		if (tl[x] < tl[y] || tl[x] > tr[y]){
			vis[y] = 1,ans[y] = min(ans[y],Tdis[x] + ez[i]);
			pp = tl[x],vv = Tdis[x] + ez[i],Add(T[y],1,n);
		}
	}
	
//	for (i = 1; i <= n; ++i) write(ans[i]),putchar(i < n ? ' ' : '\n');
	
	ans[1] = 0; vis[1] = 1; dfs_ans(1);
	
//	for (i = 1; i <= n; ++i) write(ans[i]),putchar(i < n ? ' ' : '\n');
	
	for (i = 1; i <= n; ++i){
		if (i == 1) putchar('0');
		else if (ans[i] >= INF) write(-1);
		else write((!vis[i]) ? -1 : ans[i]);
		putchar(i < n ? ' ' : '\n');
	}
	return 0;
}
