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
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
}

int k,N;
int a[35],now[35],n = 31,deg[35],G[35][35],d[35][35];
namespace Graph{
	int A[10];
	inline void add(int x,int y){ if (x && y) d[x][y] = d[y][x] = 1; }
	inline void I(int len){
		static int i,j;
		for (i = 1; i < len; ++i)
		for (j = i + 1; j <= len; ++j) add(A[i],A[j]);
	}
	inline void II(int a,int b,int c,int d,int e,int f,int g){ A[1] = a,A[2] = b,A[3] = c,A[4] = d,A[5] = e,A[6] = f,A[7] = g,I(7); }
	inline void build(){
		A[1] = 3,A[2] = 8,I(2);
		A[1] = 1,A[2] = 4,A[3] = 9,A[4] = 14,A[5] = 19,I(5);
		A[1] = 2,A[2] = 5,A[3] = 10,A[4] = 15,A[5] = 20,A[6] = 25,I(6);
		A[1] = 6,A[2] = 11,A[3] = 16,A[4] = 21,A[5] = 26,I(5);
		A[1] = 7,A[2] = 12,A[3] = 17,A[4] = 22,A[5] = 27,A[6] = 30,I(6);
		A[1] = 13,A[2] = 18,A[3] = 23,A[4] = 28,A[5] = 31,I(5);
		A[1] = 24,A[2] = 29,I(2);
		
		A[1] = 7,A[2] = 13,I(2);
		A[1] = 19,A[2] = 25,I(2);
		A[1] = 2,A[2] = 6,A[3] = 12,A[4] = 18,A[5] = 24,I(5);
		A[1] = 8,A[2] = 14,A[3] = 20,A[4] = 26,A[5] = 30,I(5);
		A[1] = 4,A[2] = 10,A[3] = 16,A[4] = 22,A[5] = 28,I(5);
		A[1] = 1,A[2] = 5,A[3] = 11,A[4] = 17,A[5] = 23,A[6] = 29,I(6);
		A[1] = 3,A[2] = 9,A[3] = 15,A[4] = 21,A[5] = 27,A[6] = 31,I(6);
		
		II(1,2,0,0,0,0,0);
		II(3,4,5,6,7,0,0);
		II(8,9,10,11,12,13,0);
		II(14,15,16,17,18,0,0);
		II(19,20,21,22,23,24,0);
		II(25,26,27,28,29,0,0);
		II(30,31,0,0,0,0,0);
		
		II(1,2,4,5,6,10,11);
		II(3,4,8,9,10,14,15);
		II(6,7,11,12,13,17,18);
		II(10,11,15,16,17,21,22);
		II(14,15,19,20,21,25,26);
		II(17,18,22,23,24,28,29);
		II(21,22,26,27,28,30,31);
		int i,j;
		for (i = 1; i <= 31; ++i)
		for (j = 1; j <= 31; ++j) if (j < i && d[i][j]) {++deg[i]; G[i][deg[i]] = j;}
	}
}
int ok[35][35];
int vis[35][35];
void dfs(int x){
	if (x>>5){ --N; if (!N){ puts("Found"); for (int i = 1; i <= 31; ++i) write(now[i]),putchar(i < 31 ? ' ' : '\n'); exit(0); } return; }
	if (a[x]){ now[x] = a[x]; dfs(x+1); return; }
	int i;
	for (i = 1; i <= k; ++i) vis[x][i] = ok[x][i];
	for (i = 1; i <= deg[x]; ++i) vis[x][now[G[x][i]]] = 0;
	for (i = 1; i <= k; ++i) if (vis[x][i]) now[x] = i,dfs(x+1);
}
int main(){
	File();
	int i,j; bool flag;
	Graph::build();
	k = read(),N = read(); 
	if (k <= 6){ puts("No way"); return 0; }
	for (i = 1; i <= 31; ++i) 
	for (j = 1; j <= k; ++j) ok[i][j] = 1;
	for (i = 1; i <= 31; ++i){
		a[i] = read(); now[i] = a[i];
		if (a[i]) for (j = 1; j <= k; ++j) ok[i][j] = (j == a[i] ? 1 : 0);
		for (j = 1; j <= 31; ++j) if (i != j && d[i][j]) ok[j][a[i]] = 0;
	}
	for (i = 1; i <= 31; ++i){
		flag = 0;
		for (j = 1; j <= k; ++j) flag |= ok[i][j];
		if (!flag) {puts("No way"); return 0;}
	}
	dfs(1);	puts("No way"); return 0;
}
