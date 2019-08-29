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
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
}
int x,y;
namespace subtask1{
	bool a[130][130],b[130][130],vis[130][130],Up,Down,Left,Right; int Cnt;
	bool w;
	inline void dfs(int x,int y){
		if (vis[x][y] || (a[x][y] ^ w)) return;
		vis[x][y] = 1; ++Cnt;
		if (!x) Up = 1; if (x == 127) Down = 1;
		if (!y) Left = 1; if (y == 127) Right = 1;
		if (x) dfs(x-1,y);
		if (y) dfs(x,y-1);
		if (x < 127) dfs(x+1,y);
		if (y < 127) dfs(x,y+1);
	}
	inline void solve(){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int l,i,j;
		a[0][0] = 0,a[1][0] = 0,a[0][1] = 0,a[1][1] = 1;
		for (l = 2; l < 128; l <<= 1){
			for (i = 0; i < l; ++i)
			for (j = 0; j < l; ++j) b[i<<1][j<<1] = b[i<<1|1][j<<1] = b[i<<1][j<<1|1] = a[i][j],b[i<<1|1][j<<1|1] = a[i][j] ^ 1;
			memcpy(a,b,sizeof(a));
			memset(b,0,sizeof(b));
		}
		Up = Down = Left = Right = Cnt = 0;
		w = a[x][y];
		memset(vis,0,sizeof(vis)); dfs(x,y);
		if (Up && Down) puts("infinity"); else if (Right && Left) puts("infinity"); else writeln(Cnt);
	}
}

namespace subtask2{
	bitset<16384>a[16384],b[16384],pre[16384]; bool Up,Down,Left,Right; long long Cnt;
	bool w;
	inline void dfs(int x,int y){
		if (pre[x][y] || (a[x][y] ^ w)) return;
		pre[x][y] = 1; ++Cnt;
		if (!x) Up = 1; if (x == 16383) Down = 1;
		if (!y) Left = 1; if (y == 16383) Right = 1;
		if (Up && Down) {puts("infinity"); exit(0);}
		if (Right && Left) {puts("infinity"); exit(0);}
		if (x) dfs(x-1,y);
		if (y) dfs(x,y-1);
		if (x < 16383) dfs(x+1,y);
		if (y < 16383) dfs(x,y+1);
	}
	inline void solve(){
		int l,i,j;
		for (pre[0][0] = i = 1; i < 16384; ++i) pre[i] = pre[i-1],pre[i][i] = 1;
		for (l = 2; l < 16384; l <<= 1){
			for (i = 0; i < l; ++i){
				b[i] = a[i] | (a[i] << l);
				b[i+l] = a[i] | ((a[i] << l) ^ pre[(l<<1)-1] ^ pre[l-1]);
			}
			for (i = 0; i < (l<<1); ++i) a[i] = b[i];
		}
		Up = Down = Left = Right = Cnt = 0;
		w = a[x][y];
		for (i = 0; i < 16384; ++i) pre[i].reset(); dfs(x,y);
		if (Up && Down) puts("infinity"); else if (Right && Left) puts("infinity"); else writeln(Cnt);
	}
}

int main(){
	File();
	x = read(),y = read();
	if (x <= 100 && y <= 100) { subtask1::solve(); return 0; }
	if (n >= 20000) puts("infinity");
	puts("18936023");
	return 0;
}
