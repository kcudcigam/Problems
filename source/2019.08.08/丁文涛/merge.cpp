#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
const int INF =2147483647;
const int SIZ =1e3;
typedef long long LL;
char bef[SIZ+3],*p1=bef,*p2=bef;
char getc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
} 
LL qread(){
	LL ret,c,w=1;
	while((c=getc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =5e5+3;
int fa[MAXN],op[MAXN][3],n,q;
int getfa(int x){
	return x==fa[x]?x:(fa[x]=getfa(fa[x]));
}
LL tot,head[MAXN],nxt[MAXN*2],ver[MAXN*2];
void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
	ver[++tot]=u,nxt[tot]=head[v],head[v]=tot;
}
LL data[MAXN],sum=0;
LL dfn[MAXN],cnt,mmp[MAXN],lft[MAXN],rgt[MAXN];
bool vis[MAXN];
void dfs(int u){
	dfn[u]=++cnt,mmp[cnt]=u;
	for(int i=head[u];i;i=nxt[i])
	if(!vis[ver[i]]) vis[ver[i]]=true,dfs(ver[i]);
}
void qwrite(LL x){
	if(x<0) x=-x,putchar('-');
	if(x>9) qwrite(x/10);
	putchar('0'+x%10);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=qread(),q=qread();
	up(1,n,i) fa[i]=i;
	up(1,q,i) op[i][0]=qread(),op[i][1]=qread(),op[i][2]=qread();
	up(1,q,i){
		int x=op[i][1],y=op[i][2];
		if(op[i][0]==1) if(getfa(x)!=getfa(y)){
			fa[y]=getfa(x),add(getfa(x),getfa(y));
		}
	}
	up(1,n,i) fa[i]=i,lft[i]=rgt[i]=i;
	up(1,q,i){
		int a=op[i][1],b=op[i][2];
		if(op[i][0]==1){
			if(getfa(a)!=getfa(b)){
				int faa=getfa(a),fab=getfa(b);
				fa[faa]=fab,lft[fab]=min(lft[fab],lft[faa]);
				rgt[fab]=max(rgt[fab],rgt[faa]);
			}
		} else{
			int L=lft[getfa(a)],R=rgt[getfa(a)];
			data[L]+=b,data[R+1]-=b;
		}
	}
	up(1,n,i){
		sum+=data[i];
		qwrite(sum),putchar(' ');
	}
	return 0;
}
/*
2 3
2 1 2147483647
1 2 1
2 1 2147483647
*/
