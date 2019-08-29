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
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
}
const int N = 255,M = 505;
int n,m,l[N],r[N],vis[N],a[M],cnt;
int A,B,C,D,E;

int x[M],lenx; LL ans = 0;
inline LL F(LL x){ return (((((x * E) + D) * x + C) * x + B) * x + A) * x; }

namespace subtask1{
	LL f[20 + 1][15 + 1][1 << 15]; bool vis[20 + 1][15 + 1][1 << 15];
	LL ls,ans;
	inline void update(int i,int j,int s,LL val){
		if (val > ans) ans = val;
		if (vis[i][j][s]) f[i][j][s] = max(f[i][j][s],val);
		else vis[i][j][s] = 1,f[i][j][s] = val;
	}
	inline void solve(){
		ls = (1 << n) - 1; ans = 0;
		int i,j,k,s;
		vis[1][0][ls] = 1;
		for (i = 1; i <= m; ++i){
			for (j = 0; j <= n; ++j)
			for (s = ls; s >= 0; --s) if (vis[i][j][s]){
				update(i+1,0,s,f[i][j][s] + F(j));
				for (k = 0; k < n; ++k) if (l[k+1] <= i && r[k+1] >= i && (s >> k & 1)) update(i,j+1,s^(1<<k),f[i][j][s]);
			}
		}
		writeln(ans);
	}
}

namespace subtask2{
	LL f[41][41][41][41],g[41][41][41][41]; bool ok[100];
	LL ff[55];
	inline void solve(){
		int i,j,k,t,p; int w,wl,wr; LL val,ans = 0;
		for (i = 1; i <= n; ++i) ff[i] = F(i) - F(i-1);
		for (i = 0; i <= n; ++i)
		for (j = 0; i + j <= n; ++j)
		for (k = 0; i + j + k <= n; ++k)
		for (t = 0; i + j + k + t <= n; ++t) f[i][j][k][t] = -1;
		f[0][0][0][0] = 0;
		for (w = 1; w <= n; ++w){
			wl = l[w],wr = r[w];
			for (i = 1; i <= 5; ++i) if (wl <= i && i <= wr) ok[i] = 1; else ok[i] = 0;
			for (i = 0; i <= w; ++i)
			for (j = 0; i + j <= w; ++j)
			for (k = 0; i + j + k <= w; ++k) 
			for (t = 0; i + j + k + t <= w; ++t) g[i][j][k][t] = -1;
			for (i = 0; i < w; ++i)
			for (j = 0; i + j < w; ++j)
			for (k = 0; i + j + k < w; ++k) 
			for (t = 0; i + j + k + t < w; ++t) if ((val = f[i][j][k][t]) >= 0){
				p = w - 1 - i - j - k - t;
				ans = max(ans,val);
				if (ok[1]) g[i+1][j][k][t] = max(g[i+1][j][k][t],val + ff[i+1]);
				if (ok[2]) g[i][j+1][k][t] = max(g[i][j+1][k][t],val + ff[j+1]);
				if (ok[3]) g[i][j][k+1][t] = max(g[i][j][k+1][t],val + ff[k+1]);
				if (ok[4]) g[i][j][k][t+1] = max(g[i][j][k][t+1],val + ff[t+1]);
				if (ok[5]) g[i][j][k][t] = max(g[i][j][k][t],val + ff[p+1]);
			}
			for (i = 0; i <= w; ++i)
			for (j = 0; i + j <= w; ++j)
			for (k = 0; i + j + k <= w; ++k) 
			for (t = 0; i + j + k + t <= w; ++t) f[i][j][k][t] = g[i][j][k][t];
		}
		for (i = 0; i <= n; ++i)
		for (j = 0; i + j <= n; ++j)
		for (k = 0; i + j + k <= n; ++k) 
		for (t = 0; i + j + k + t <= n; ++t) ans = max(ans,f[i][j][k][t]);
		writeln(ans);
	}
}

int main(){
	File();
	int i,pos;
	n = read(),m = read();
	A = read(),B = read(),C = read(),D = read(),E = read();
	for (i = 1; i <= n; ++i){ l[i] = read(),r[i] = read(); ++lenx; x[lenx] = l[i]; ++lenx; x[lenx] = r[i]; }
	sort(x+1,x+lenx+1); lenx = unique(x+1,x+lenx+1) - x - 1;
	for (i = 1; i <= n; ++i) l[i] = lower_bound(x+1,x+lenx+1,l[i]) - x,r[i] = lower_bound(x+1,x+lenx+1,r[i]) - x;
	m = lenx;
	if (n <= 15 && m <= 20){ subtask1::solve(); return 0; }
	if (n <= 40 && m <= 5){ subtask2::solve(); return 0; }
	
	cnt = n;
	while (cnt){
		for (i = 1; i <= lenx; ++i) a[i] = 0;
		for (i = 1; i <= n; ++i) if (!vis[i]) a[l[i]]++,a[r[i]+1]--;
		a[0] = 0; for (i = 1; i <= lenx; ++i) a[i] += a[i-1];
		pos = 1; for (i = 2; i <= lenx; ++i) if (a[i] > a[pos]) pos = i;
		for (i = 1; i <= n; ++i) if (!vis[i] && l[i] <= pos && r[i] >= pos) vis[i] = 1,--cnt;
		ans += F(a[pos]);
	}
	writeln(ans);
	return 0;
}
