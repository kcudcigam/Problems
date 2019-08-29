#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;

int fa[maxn],juice[maxn];
int n,q;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int findfa(int x){
	if(fa[x]==x) return x;
	else return fa[x]=findfa(fa[x]);
}

void merge(int x,int y){
	if(x==y) return;
	if(findfa(x)==findfa(y)) return;
	srand((unsigned)time(NULL));
	if(rand()%2)
		fa[findfa(x)]=findfa(y);
	else
		fa[findfa(y)]=findfa(x);
}

void lemon(int x,int y){
	int totfa=findfa(x);
	for(rint i=1;i<=n;++i)
		if(findfa(i)==totfa) juice[i]+=y;
}

int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n); read(q);
	for(rint i=1;i<=n;++i) fa[i]=i;
	int cho,a,b;
	for(rint i=1;i<=q;++i){
		read(cho); read(a); read(b);
		if(cho==1)
			merge(a,b);
		else
			lemon(a,b);
//		for(rint i=1;i<=n;++i) printf("%d ",juice[i]); printf("\n");
	}
	for(rint i=1;i<=n;++i)
		printf("%d ",juice[i]);
	return 0;
}

