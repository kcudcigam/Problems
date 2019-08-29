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
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
}

const int N = 200005,P = 1000000000 + 7;
struct Edge{ int x,y; }e1[N],e2[N];

int Num,n,m1,m2;

namespace subtask1{
	int a[50],vis[50]; LL cnt;
	int d1[50][50],d2[50][50];
	inline void checker(){
		static int i,x,y;
		for (i = 1; i <= m1; ++i){
			x = a[e1[i].x],y = a[e1[i].y];
			if (!d1[x][y]) {++cnt; return;}
		}
		for (i = 1; i <= m2; ++i){
			x = a[e2[i].x],y = a[e2[i].y];
			if (!d2[x][y]) {++cnt; return;}
		}
	}
	inline void dfs(int dep){
		if (dep > n) {checker(); return;}
		else for (int i = 1; i <= n; ++i) if (!vis[i]) a[dep] = i,vis[i] = 1,dfs(dep+1),vis[i] = 0;
	}
	inline void solve(){
		int i;
		cnt = 0;
		for (i = 1; i <= n; ++i) vis[i] = 0;
		for (i = 1; i <= m1; ++i) d1[e1[i].x][e1[i].y] = d1[e1[i].y][e1[i].x] = 1;
		for (i = 1; i <= m2; ++i) d2[e2[i].x][e2[i].y] = d2[e2[i].y][e2[i].x] = 1;
		dfs(1);
		writeln(cnt % P);
	}
}

int main(){
File();
	int i;
	Num = read(),n = read(),m1 = read(),m2 = read();
	for (i = 1; i <= m1; ++i) e1[i].x = read(),e1[i].y = read();
	for (i = 1; i <= m2; ++i) e2[i].x = read(),e2[i].y = read();
	if (n <= 10){ subtask1::solve(); return 0; }
	
	
	return 0;
}
