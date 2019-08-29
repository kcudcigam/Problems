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
int a[300010];int b[300010];
struct wzy{
	int nxt,vertice;
}edge[600010];
int head[300010];int len=0;
inline void add_edge(int x,int y){
	edge[++len].nxt=head[x];edge[len].vertice=y;
	head[x]=len;return;
}

int dep[300010];int f[300010][20];
inline void Pretreatment(int son,int father){
	dep[son]=dep[father]+1;f[son][0]=father;
	rep(i,1,19)f[son][i]=f[f[son][i-1]][i-1];
	for(int i=head[son];i;i=edge[i].nxt){
		int nop=edge[i].vertice;
		if(nop==father)continue;
		Pretreatment(nop,son);
	}
	return;
}
inline int LCA(int x,int y){
	if(dep[x]<=dep[y])swap(x,y);
	rep2(i,19,0){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
		if(x==y)return x;
	}
	rep2(i,19,0){
		if(f[x][i]!=f[y][i]){x=f[x][i];y=f[y][i];}
	} 
	return f[x][0];
}
inline int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}

int ZJ[300010][3];int fa[300010];
inline int root_seeking(int x){
	if(fa[x]!=x)fa[x]=root_seeking(fa[x]);
	return fa[x];
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	
	int n;read(n);
	rep(i,1,n-1){
		read(a[i]);read(b[i]);
		add_edge(a[i],b[i]);add_edge(b[i],a[i]);
	}
	Pretreatment(1,0);
	
	rep(i,1,n){ZJ[i][0]=0;ZJ[i][1]=ZJ[i][2]=i;fa[i]=i;}
	rep(i,1,n-1){
		int n1=root_seeking(a[i]);int n2=root_seeking(b[i]);
		int w1=ZJ[n1][0];int w2=ZJ[n2][0];
		int t1=dis(a[i],ZJ[n1][1]);int p1=ZJ[n1][1];
		int t2=dis(a[i],ZJ[n1][2]);
		if(t2>t1){t1=t2;p1=ZJ[n1][2];}
		int w3=t1;
		t1=dis(b[i],ZJ[n2][1]);int p2=ZJ[n2][1];
		t2=dis(b[i],ZJ[n2][2]);
		if(t2>t1){t1=t2;p2=ZJ[n2][2];}
		w3+=t1;w3++;
		
		if(w1>w2&&w1>w3){fa[n2]=n1;write(w1);}
		else if(w2>w1&&w2>w3){fa[n1]=n2;write(w2);}
		else{
			fa[n2]=n1;ZJ[n1][0]=w3;ZJ[n1][1]=p1;ZJ[n1][2]=p2;
			write(w3);
		}
	}
	return 0;
}
