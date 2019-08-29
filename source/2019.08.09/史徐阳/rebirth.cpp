#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
template<class T>inline void read(T&n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
const int N = 1e5 + 5;
struct Node{
	LL v, e, f;
	Node(LL a, LL b, LL c){
		v = a, e = b, f = c;
	}
};
vector<Node>vv[2*N];
LL n, m, Num;
LL ans[2*N], dis[2*N], vis[2*N];
void SPFA(int org){
	queue<int>qq;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[org] = 0;vis[org] = 1;
	qq.push(org);
	while (qq.size()){
		int u = qq.front();
		qq.pop();vis[u] = 0;
		for (register size_t i = 0;i < vv[u].size();i ++){
			if (vv[u][i].f) continue;
			int v = vv[u][i].v, e = vv[u][i].e;
			if (dis[v] > dis[u] + e){
				dis[v] = dis[u] + e;
				if (!vis[v])
					qq.push(v),vis[v] = 1;
			}
		}
	}
	ans[org] = max(ans[org], dis[1]);
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(Num), read(n), read(m);
	for (register int i = 1;i <= m;i ++){
		LL u, v, e;
		read(u), read(v), read(e);
		vv[u].push_back(Node(v, e, 0));
		vv[v].push_back(Node(u, e, 0));
	}
	for (register int i = 2;i <= n;i ++)
		for (register size_t j = 0;j < vv[i].size();j ++){
			vv[i][j].f = 1;
			SPFA(i);
			vv[i][j].f = 0;
		}
	for (register int i = 1;i <= n;i ++){
		if (i > 1)putchar(' ');
		printf("%lld", ans[i] == INF?-1:ans[i]);
	}
	return 0;
}


