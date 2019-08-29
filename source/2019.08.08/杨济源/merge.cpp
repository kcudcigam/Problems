#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 5e5 + 5;

int add[N], del[N], son[N], Rank[N];
LL Start[N], End[N], res[N];
bool vis[N];
int n, q;

inline void dfs(int x)
{
	LL now = 0;
	while (x)
	{
		vis[x] = 1;
		
		now += add[x];
		
		res[x] = now;
		
		now -= del[x];
	
		x = son[x];
	}
}
int main(){
	freopen ("merge.in", "r", stdin);
	freopen ("merge.out", "w", stdout);
	
	read(n); read(q);
	
	for (int i = 1; i <= n; i++) Rank[i] = Start[i] = End[i] = i;
	
	int op, x, y;
	
	for (int i = 1; i <= q; i++)
	{
		read(op); read(x); read(y);
		
		if (op == 2)
		{
			add[Start[Rank[x]]] += y;
			del[End[Rank[x]]] += y;
		}
		
		if (op == 1)
		{
			if (x > y) swap(x, y);
			
			son[End[Rank[x]]] = Start[Rank[y]];

			End[Rank[x]] = End[Rank[y]];
			
			Rank[y] = Rank[x];
		}
	}
	
	for (int i = 1; i <= n; i++)
	if (!vis[i]) dfs(i);
	
	for (int i = 1; i <= n - 1; i++) printf("%lld ", res[i]);
	printf("%lld\n", res[n]);
  return 0;
}
