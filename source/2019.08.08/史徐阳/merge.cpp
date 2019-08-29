#include<bits/stdc++.h>
#define pii pair<int,int>
#define make make_pair
using namespace std;
template<class T>inline void read(T &n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if (ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
const int N = 500005;
int fa[N], t[N];
vector<int>v[N];
vector<pii >stay[N];
int Find(int x){
	if (fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
inline void Merge(int x, int y){
	if (Find(x) ==  Find(y))return;
	stay[y].push_back(make(Find(x),++ t[Find(x)]));
	v[Find(x)].push_back(0);
	fa[Find(y)] = fa[Find(x)];
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n, T;
	read(n), read(T);
	for (int i = 1;i <= n;i ++){
		fa[i] = i;
		stay[i].push_back(make(i, 0));
		v[i].push_back(0);
	}
	while(T --){
		int op, x, y;
		read(op), read(x), read(y);
		if (op==1) Merge(x, y);
		else v[Find(x)][v[Find(x)].size()-1] += y;
	}
	for (int i = 1;i <= n;i ++){
		if (i > 1)putchar(' ');
		int tmp = 0;
		for (size_t j = 0;j < stay[i].size();j ++)
			for (size_t k = stay[i][j].second;k < v[stay[i][j].first].size();k ++)
				tmp += v[stay[i][j].first][k];
		printf("%d", tmp);
	}
	puts("");
	return 0;
}

