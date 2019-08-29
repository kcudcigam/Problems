#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
int n,m,Q;
int val[MAXN];
vector<int> g[MAXN];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n),read(m),read(Q);
	for (int i=1;i<=m;i++){
		int x,y;
		read(x),read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	while (Q--){
		int opt,x,y;
		read(opt),read(x);
		if (opt==0){
			printf("%d\n",val[x]);
		}else{
			read(y);
			val[x]+=y;
			for (int i=0;i<g[x].size();i++)
				val[g[x][i]]+=y;
		}
	}
	return 0;
}
/*
4 4 4
1 2
1 3
1 4
2 3
1 1 1
0 2
1 3 3
0 2
*/



