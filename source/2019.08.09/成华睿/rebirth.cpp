#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 400005;
struct node{
	friend bool	operator <(node a, node b){
		return a.dis > b.dis;
	}
	int num;
	ll dis;
}g;
priority_queue <node> q;
int head[N], nex[N], to[N], h[N], from[N];
int n, m, x, y, num, cnt, del;
ll dis[N], dist[N], ans[N];
ll z;
void spfa(int ban){
	del = (from[ban]+1)/2;
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	memset(h, 0, sizeof h);
	dis[1] = 0;
	g.num = 1;
	g.dis = 0;
	q.push(g);
	for (; !q.empty(); q.pop()){
		x = q.top().num;
		if (h[x] == 1) continue;
		for (int i = head[x]; i; i = nex[i]){
			y = to[i];
			z = dist[i];
			if (i != del*2-1 && i != del*2 && dis[x]+z < dis[y]){
				dis[y] = dis[x]+z;
				g.num = y;
				g.dis = dis[y];
				q.push(g);
				if (ban == 0) from[y] = i;
			}
		}
		h[x] = 1;
	}
	ans[ban] = dis[ban];
	return;
}
int main(){
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	cin >> num >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> x >> y >> z;
		nex[++cnt] = head[x];
		head[x] = cnt;
		to[cnt] = y;
		dist[cnt] = z;
		nex[++cnt] = head[y];
		head[y] = cnt;
		to[cnt] = x;
		dist[cnt] = z;
	}
	spfa(0);
	for (int i = 1; i <= n; i++) spfa(i);
	for (int i = 1; i <= n; i++)
		if (ans[i] == 1e18)
			cout << -1 << ' '; else
			cout << ans[i] << ' ';
	cout << endl;
	return 0;
}


