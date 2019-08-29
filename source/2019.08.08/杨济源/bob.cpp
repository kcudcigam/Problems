#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 20;
int a[N], d[N], now[N];
int n;
int ans;
bool vis[N][N][N][N];
bool visnow[N][N][N][N];
inline int dfs()
{
	if (vis[d[1]][d[2]][d[3]][d[4]]) return 1;
	memset(visnow, 0, sizeof(visnow));
	for (int i = 1; i <= 4; i++) now[i] = d[i];
	while (!visnow[now[1]][now[2]][now[3]][now[4]])
	{
		if (now[1] == 0 && now[2] == 0 && now[3] == 0 && now[4] == 0) return 0;
		if (now[1] != 1 && now[2] != 1 && now[3] != 1 && now[4] != 1) return 0;
		visnow[now[1]][now[2]][now[3]][now[4]] = 1;
		for (int i = 1; i <= 4; i++)
		{
			if (now[i]) now[i]--;
			if (now[i] == 0) continue;
			for (int j = 1; j <= 4; j++)
			if (!now[j])
			{
				now[j] = a[now[i]];
				break;
			}
		}	
	}
	for (int i = 0; i <= n; i++)
	 for (int j = 0; j <= n; j++)
	  for (int k = 0; k <= n; k++)
	   for (int l = 0; l <= n; l++)
	    vis[i][j][k][l] |= visnow[i][j][k][l];
	return 1;
}
inline void prework(int dep)
{
	if (dep > 4)
	{
		if (dfs()) ans++;
		return;
	}
	
	for (int i = 0; i <= n; i++) d[dep] = i, prework(dep + 1);
}
int main(){
	freopen ("bob.in", "r", stdin);
	freopen ("bob.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n - 1; i++) read(a[i]);
	
	prework(1);
	printf("%d\n", ans);
  return 0;
}
