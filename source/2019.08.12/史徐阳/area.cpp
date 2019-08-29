#include<bits/stdc++.h>
using namespace std;
const int t[5][5] = {{0, 1},{0, -1},{-1, 0},{1, 0}};
int s[2050][2050], h[2050][2050];
int x, y, ans = 0;
void make(int nlen){
	if (nlen == 2048)return;
	for (int i = nlen;i >= 1;i --)
		for (int j = nlen;j >= 1;j --){
			int tx = i * 2, ty = j * 2;
			s[tx][ty] = s[i][j] * -1;
			s[tx][ty - 1] = s[tx - 1][ty] = s[tx - 1][ty - 1] = s[i][j] * 1;
		}
	make(nlen * 2);		
}
void dfs(int x,int y,int dep){
	ans ++;
	h[x][y] = 1;
	if (ans > 128){
		puts("infinity");
		exit(0);
	}
	for (int i = 0;i < 4;i ++){
		int tx = x + t[i][0];
		int ty = y + t[i][1];
		if (tx&&ty&&!h[tx][ty]&&s[x][y]==s[tx][ty])
			dfs(tx, ty, dep + 1);
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	s[1][1] = s[1][2] = s[2][1] = 1;
	s[2][2] = -1;
	make(2);
	scanf("%d%d", &x, &y);
	x++, y++;
	dfs(x, y, 1);
	printf("%d\n", ans);
	return 0;
}

