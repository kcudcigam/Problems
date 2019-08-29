#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =INT_MAX;
const int SIZ =1e5;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int w=1,c,ret;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =3e5+3;
struct Node{
	int u,v,val;
	bool operator <(const Node t) const{return val<t.val;}
}edg[MAXN];
int n,m,q,_fa[MAXN];
int getfa(int u){
	return u==_fa[u]?u:(_fa[u]=getfa(_fa[u]));
}
int tot,head[MAXN],nxt[MAXN*2],ver[MAXN*2],val[MAXN*2];
void add(int u,int v,int w){
	ver[++tot]=v,nxt[tot]=head[u],val[tot]=w,head[u]=tot;
} 
int ST[20+3][MAXN],fa[20+3][MAXN],dis[MAXN];
void bld(int u){
	for(int i=head[u];i;i=nxt[i])
	if(!fa[0][ver[i]]) dis[ver[i]]=dis[u]+1,fa[0][ver[i]]=u,ST[0][ver[i]]=val[i],bld(ver[i]);
}
void init(){
	up(1,3,j) up(1,n,i) fa[j][i]=fa[j-1][fa[j-1][i]];
	up(1,3,j) up(1,n,i) ST[j][i]=max(ST[j-1][i],ST[j-1][fa[j-1][i]]);
}
int calc(int x,int y){
	if(getfa(x)!=getfa(y)) return -1;
	int ret=0;
	if(dis[x]<dis[y]) swap(x,y);
	if(dis[x]!=dis[y]){
		int k=1;
		while(k){
			if(dis[fa[k][x]]>dis[y])
			ret=max(ret,ST[k][x]),x=fa[k][x],k++;
			else k--;
		} 
		ret=max(ret,ST[0][x]),x=fa[0][x];
	}
	if(x==y) return ret;
	int k=1;
	while(k){
		if(fa[k][x]!=fa[k][y]){
			x=fa[k][x],y=fa[k][y];
			ret=max(max(ret,ST[k][y]),ST[k][x]),k++;
		}else k--;
	}
	ret=max(max(ret,ST[0][x]),ST[0][y]);
	return ret;
}
int main(){
	freopen("graph","r",stdin);
	freopen("graph","w",stdout);
	
	n=qread(),m=qread(),q=qread();
	up(1,n,i) _fa[i]=i;
	up(1,m,i) edg[i].u=qread(),edg[i].v=qread(),edg[i].val=qread();
	sort(edg+1,edg+1+m);
	up(1,m,i){
		int u=edg[i].u,v=edg[i].v,w=edg[i].val,fau=getfa(u),fav=getfa(v);
		if(fau!=fav) add(u,v,w),add(v,u,w),_fa[fau]=fav;
	}
	up(1,n,i) if(!fa[0][i]) dis[i]=1,fa[0][i]=i,bld(i);
	init();
	up(1,q,i){
		int x=qread(),y=qread();
		printf("%d\n",calc(x,y));
	}
	return 0;
}
/*
13 15 20
1 2 2
2 4 9
2 5 8
4 5 6
5 8 1
8 6 7
6 3 9
1 3 6
3 13 1
3 7 1
7 13 8
7 9 100
10 11 2
10 12 3
11 12 4
*/
