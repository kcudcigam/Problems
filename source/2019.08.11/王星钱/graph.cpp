#include <bits/stdc++.h>
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar(48); if (x<0)x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
const int MAXN=600010;
int rev[MAXN],mx[MAXN],val[MAXN],fa[MAXN],ch[MAXN][2];
inline void pushup(int x){
	int l=ch[x][0],r=ch[x][1];
	mx[x]=max(val[x],max(mx[l],mx[r]));
}
inline void setr(int x){
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
inline void pushdown(int x){
	if (rev[x]){
		setr(ch[x][0]);
		setr(ch[x][1]);
		rev[x]=0;
	}
}
inline int isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline int chk(int x){return ch[fa[x]][1]==x;}
void rotate(int x){
	int y=fa[x],z=fa[y];
	int k=chk(x),k1=chk(y);
	int w=ch[x][k^1];
	ch[y][k]=w; if (w)fa[w]=y;
	if (!isroot(y))ch[z][k1]=x; fa[x]=z;
	ch[x][k^1]=y;fa[y]=x;
	pushup(y),pushup(x);
}
void pushall(int x){
	if (!isroot(x))pushall(fa[x]);
	pushdown(x);
}
void splay(int x){
	pushall(x);
	while (!isroot(x)){
		int y=fa[x];
		if (!isroot(y))
			rotate(chk(x)^chk(y)?x:y);
		rotate(x);
	}
}
void access(int x){
	for (int y=0;x;x=fa[y=x])
		splay(x),ch[x][1]=y,pushup(x);
}
void makeroot(int x){
	access(x);splay(x);setr(x);
}
void split(int x,int y){
	makeroot(x);access(y);splay(y);
}
void link(int x,int y){
	makeroot(x);
	fa[x]=y;
}
struct edge{
	int u,v,w;
	bool operator < (const edge& k1)const{
		return w<k1.w;
	}
}e[MAXN];
int pa[MAXN];
inline int findpa(int x){
	return x==pa[x]?x:pa[x]=findpa(pa[x]);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,Q;
	read(n),read(m),read(Q);
	for (int i=1;i<=m;i++){
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++)
		val[i+n]=mx[i+n]=e[i].w;
	for (int i=1;i<=n;i++)pa[i]=i;
	int cnt=1;
	for (int i=1;i<=m;i++){
		int x=findpa(e[i].u),y=findpa(e[i].v);
		if (x==y)continue;
		pa[y]=x;
		link(e[i].u,i+n);link(i+n,e[i].v);
		cnt++;
		if (cnt==n)break;
	}
	while (Q--){
		int x,y;
		read(x),read(y);
		if (findpa(x)!=findpa(y)){
			puts("-1");
			continue;
		}
		split(x,y);
		write(mx[y]),putchar('\n');
	}
	return 0;
}
/*
5 5 4
1 2 3
1 3 2
3 2 1
1 4 5
2 4 4
1 2
1 4
3 5
2 4
*/
/*
9 13 5
1 2 1
2 3 2
3 1 3
1 4 4
4 5 5
4 6 6
6 4 13
6 5 17
3 7 19
7 5 1
7 8 9
8 9 9
9 7 12
2 6
4 3
8 3
5 2
6 8
*/
