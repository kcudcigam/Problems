#include<bits/stdc++.h>
#define N 500010
#define D 26
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,q;
struct node{
	int x,y,type;
};
node a[N];
int f[N<<1];
int par(int x){
	if (f[x]==x) return x;
	f[x]=par(f[x]);
	return f[x];
}
struct side{
	int t,son[2];
};
int head[N<<1];
int tot;
side c[N<<1];
int len;
int fa[N<<1][D];
int h[N<<1];
void dfs(int p){
	for (int i=0;i<=1;i++){
		int k=c[p].son[i];
		if (k){
			for (int j=1;fa[k][j-1];j++,h[k]++) fa[k][j]=fa[fa[k][j-1]][j-1];
			dfs(k);
		}
	}
	return;
}
int ans[N<<1];
int find(int k,int now){
	int hi=h[k];
	for (int i=hi;i>=0;i--)
		if (fa[k][i]&&c[fa[k][i]].t<now)
			k=fa[k][i];
	return k;
}
void count(int p){
	if (c[p].son[0]){
		ans[c[p].son[0]]+=ans[p];
		ans[c[p].son[1]]+=ans[p];
		count(c[p].son[0]);
		count(c[p].son[1]);
	}
	return;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for (int i=1;i<=n+q;i++) f[i]=i;
	tot=n;
	for (int i=1;i<=q;i++){
		read(a[i].type);
		read(a[i].x);
		read(a[i].y);
		if (a[i].type==1){
			int k1=par(a[i].x),k2=par(a[i].y);
			if (k1!=k2){
				++tot;
				c[tot].t=i;
				c[tot].son[0]=k1;
				c[tot].son[1]=k2;
				fa[k1][0]=tot;
				fa[k2][0]=tot;
				f[par(a[i].x)]=tot;
				f[par(a[i].y)]=tot;
			}
		}
	}
	for (int i=1;i<=tot;i++) if (!fa[i][0]) dfs(i);
	for (int i=1;i<=q;i++){
		if (a[i].type==2){
			int w=find(a[i].x,i);
			ans[w]+=a[i].y;
		}
	}
	for (int i=1;i<=tot;i++) if (!fa[i][0]) count(i);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}

