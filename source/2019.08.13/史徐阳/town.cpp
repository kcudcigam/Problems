#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
namespace In_Out_put{
	template<class T>inline void read(T&n){
		n = 0;T f = 1;char ch;
		for (;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f *= -1;
		for (;ch >= '0' && ch <= '9';ch = getchar())n = (n<<1) + (n<<3) + (ch^48);
		n *= f;
	}
	template<class T>inline void write(T n){
		if (n == 0)putchar('0');
		if (n < 0) n = -n,putchar('-');
		static char buf[233];int tmp = 0;
		while (n) buf[++ tmp] = n % 10 + '0', n /= 10;
		while (tmp) putchar(buf[tmp --]);
	}
	template<class T>inline void writeln(T n){
		write(n);
		puts("");
	}
}
using namespace In_Out_put;
const int N = 5005;
class Disjoint_Set{
protected:
	int rank[N], fa[N];
public:
	Disjoint_Set(int size){
		for (int i = 1;i <= size;i ++)
			fa[i] = i, rank[i] = 1;
	}
	int find(int x){
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	inline void merge(int x, int y){
		int p1 = find(x);
		int p2 = find(y);
		if (rank[p1] < rank[p2]) fa[p1] = p2;
		else{
			fa[p2] = p1;
			if (rank[p1] == rank[p2]) rank[p1] ++;
		}
	}
	inline bool is_same(int x, int y){
		return fa[x] == fa[y]; 
	}
};
int n, tot = 0;
int head[N], var[N], next[N], dis[N];
inline void add(int u, int v){
	var[++ tot] = v;
	next[tot] = head[u];
	head[u] = tot;
}
void Dijkstra(int org){
	priority_queue<pair<int, int> >pq;
	memset(dis, 0x3f, sizeof(dis));
	dis[org] = 0;
	pq.push(make_pair(0, org));
	while (pq.size()){
		int u = pq.top().second;pq.pop();
		for (int i = head[u];i;i = next[i])
			if (dis[u] + 1 < dis[var[i]]){
				dis[var[i]] = dis[u] + 1;
				pq.push(make_pair(-dis[var[i]], var[i]));
			}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	Disjoint_Set s(n);
	for (int i = 1;i < n;i ++){
		int u, v, ans = 0;
		read(u), read(v);
		s.merge(u, v);
		add(u, v); add(v, u);
		for (int j = 1;j <= n;j ++){
			if (s.is_same(u, j)){
				Dijkstra(j);
				for (int k = 1;k <= n;k ++)
					if (dis[k] != INF)
						ans = max(ans, dis[k]);
			}	
		}
		writeln(ans);
	}
	return 0;
}

