#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;} 
struct wzy{
	int x,y,w;
}bj[300010];
int fa[300010];int num[300010];
inline int root_seeking(int x){
	if(fa[x]!=x)fa[x]=root_seeking(fa[x]);
	return fa[x];
}
inline bool cmp(wzy a,wzy b){
	return a.w<b.w;
}

struct yy{
	int nxt,vertice,v;
}edge[300010];
int head[300010];int len=0;
inline void add_edge(int x,int y,int z){
	edge[++len].nxt=head[x];edge[len].vertice=y;
	edge[len].v=z;head[x]=len;return;
}
int tot=0;
inline void dfs(int x,int tmp){
	num[x]=tmp;
	for(int i=head[x];i;i=edge[i].nxt){
		if(!num[edge[i].vertice])dfs(edge[i].vertice,tmp);
	}
	return;
}

int dep[300010];int f[300010][20];int mx[300010][20];
inline void Pretreatment(int son,int father){
	dep[son]=dep[father]+1;f[son][0]=father;
	rep(i,1,19)f[son][i]=f[f[son][i-1]][i-1];
	rep(i,1,19)mx[son][i]=max(mx[son][i-1],mx[f[son][i-1]][i-1]);
	for(int i=head[son];i;i=edge[i].nxt){
		int nop=edge[i].vertice;
		if(nop==father)continue;
		mx[nop][0]=edge[i].v;Pretreatment(nop,son);
	}
	return;
}
inline int Query(int x,int y){
	if(dep[x]<=dep[y])swap(x,y);
	int ret=0;
	rep2(i,19,0){
		if(dep[f[x][i]]>=dep[y]){chkmax(ret,mx[x][i]);x=f[x][i];}
		if(x==y)return ret;
	}
	rep2(i,19,0){
		if(f[x][i]!=f[y][i]){
			chkmax(ret,mx[x][i]);chkmax(ret,mx[y][i]);
			x=f[x][i];y=f[y][i];
		}
	}
	chkmax(ret,mx[x][0]);chkmax(ret,mx[y][0]);return ret;
}

int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	int n,m,Q;read(n);read(m);read(Q);
	rep(i,1,m){read(bj[i].x);read(bj[i].y);read(bj[i].w);}
	rep(i,1,m){
		add_edge(bj[i].x,bj[i].y,bj[i].w);
		add_edge(bj[i].y,bj[i].x,bj[i].w);
	}
	rep(i,1,n){if(!num[i]){dfs(i,tot+1);tot++;}}
	memset(head,0,sizeof(head));len=0;
	
	rep(i,1,n)fa[i]=i;
	sort(bj+1,bj+m+1,cmp);
	int tmp=0;
	rep(i,1,m){
		int n1=root_seeking(bj[i].x);int n2=root_seeking(bj[i].y);
		if(n1!=n2){
			fa[n1]=n2;tmp++;
			add_edge(bj[i].x,bj[i].y,bj[i].w);
			add_edge(bj[i].y,bj[i].x,bj[i].w);
		}
		if(tmp==n-1)break;
	}
	
	rep(i,1,n){
		if(!dep[i])Pretreatment(i,0);
	}
	rep(i,1,Q){
		int x,y;read(x);read(y);
		write((num[x]!=num[y])?-1:Query(x,y));
	}
	return 0;
} 
