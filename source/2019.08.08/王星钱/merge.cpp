#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if(ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar('0');if (x<0)x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
int size[MAXN],val[MAXN],fa[MAXN],ch[MAXN][2],add[MAXN];
void pushup(int x){
	size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void setadd(int x,int v){
	val[x]+=v;
	add[x]+=v;
}
void pushdown(int x){
	if (add[x]){
		setadd(ch[x][0],add[x]);
		setadd(ch[x][1],add[x]);
		add[x]=0;
	}
}
inline int chk(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int y=fa[x],z=fa[y];
	int k=chk(x),k1=chk(y);
	int w=ch[x][k^1];
	ch[y][k]=w; if(w)fa[w]=y;
	ch[z][k1]=x;fa[x]=z;
	ch[x][k^1]=y;fa[y]=x;
	pushup(y),pushup(x);
}
void pushall(int x){
	if (fa[x])pushall(fa[x]);
	pushdown(x);
}
void splay(int x,int goal=0){
	pushall(x);
	while (fa[x]!=goal){
		int y=fa[x],z=fa[y];
		if (z!=goal)
			rotate(chk(x)^chk(y)?x:y);
		rotate(x);
	}
}
int kth(int k,int rt){
	int x=rt;
	if (k>size[x])return 0;
	while (233){
		pushdown(x);
		if (k<=size[ch[x][0]])
			x=ch[x][0];
		else if (k==size[ch[x][0]]+1)
			return x;
		else{
			k-=size[ch[x][0]]+1;
			x=ch[x][1];
		}
	}
}
int pa[MAXN];
int findpa(int x){
	return x==pa[x]?x:pa[x]=findpa(pa[x]);
}
void merge(int u,int v){
	int x=findpa(u),y=findpa(v);
	if (x==y)return;
	splay(x),splay(y);
	if (size[x]<size[y])swap(x,y);
	int k1=kth(size[x],x);
	splay(k1);ch[k1][1]=y;fa[y]=k1;
	pushup(k1);
	pa[y]=x;
}
void modify(int x,int v){
	splay(x);
	setadd(x,v);
}
int ans[MAXN];
void dfs(int x){
	pushdown(x);
	ans[x]=val[x];
	if (ch[x][0])dfs(ch[x][0]);
	if (ch[x][1])dfs(ch[x][1]);
}
int n,Q;
void output(int x){
	pushdown(x);
	if (ch[x][0])output(ch[x][0]);
	printf("(%d: %d) ",x,val[x]);
	if (ch[x][1])output(ch[x][1]);
}
void print(){
	for (int i=1;i<=n;i++)
		if (fa[i]==0)output(i),putchar('\n');
}
int main(){
#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(Q);
	for (int i=1;i<=n;i++)
		pa[i]=i,size[i]=1;
	while (Q--){
		int opt,x,y;
		read(opt),read(x),read(y);
		if (opt==1)merge(x,y);
		else if (opt==2)modify(x,y);
//		print();
	}
	for (int i=1;i<=n;i++)
		if (fa[i]==0)dfs(i);
	for (int i=1;i<=n;i++){
		if (i-1)putchar(' ');
		write(ans[i]);
	}
	return 0;
}
/*
5 6
1 2 3
2 3 5
1 3 4
2 1 8
2 4 7
1 5 4

*/
