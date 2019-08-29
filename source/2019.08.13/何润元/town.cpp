#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define P pair
#define M make_pair
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	ull y=0;
	T l=0;
	if(!x){putchar(48);return;}
	if(x<0){x=-x;putchar('-');}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
const int N=3e5+1000;
int n,cnt,nxt[2*N],to[2*N],head[2*N],fa[N],depth[N],dd[N][2],su[N],father[N][22];
struct yy{
	int x,y;
}edge[2*N];
inline void addedge(int x,int y){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
}
inline void add(int x,int y){
	addedge(x,y);
	addedge(y,x);
}
inline void build_tree(int x){
	for(int i=head[x];i;i=nxt[i])
		if(father[x][0]!=to[i]){
			father[to[i]][0]=x;
			depth[to[i]]=depth[x]+1;
			build_tree(to[i]);
		}
}
inline void pre_lca(){
	F(i,1,20)
		F(j,1,n)
			father[j][i]=father[father[j][i-1]][i-1];
}
inline void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
inline int lca(int x,int y){
	if(depth[x]>depth[y])swap(x,y);
	DF(i,20,0)if(depth[father[y][i]]>=depth[x])y=father[y][i];
	if(x==y)return x;
	DF(i,20,0)if(father[x][i]!=father[y][i]){x=father[x][i];y=father[y][i];}
	return father[x][0];
}
inline int dis(int x,int y){return depth[x]+depth[y]-2*depth[lca(x,y)];}
inline int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	F(i,1,n){
		fa[i]=i;
		dd[i][0]=i;
		dd[i][1]=i;
		su[i]=0;
	}
	F(i,1,n-1){
		read(edge[i].x);
		read(edge[i].y);
		add(edge[i].x,edge[i].y);
	}
	depth[1]=1;build_tree(1);
	pre_lca();
	F(i,1,n-1){
		int x=get(edge[i].x),y=get(edge[i].y),nx,ny,nsu;
		if(su[x]>su[y]){nx=dd[x][0],ny=dd[x][1],nsu=su[x];}
		else{nx=dd[y][0],ny=dd[y][1],nsu=su[y];}
		F(j,0,1)
			F(k,0,1){
				int l=dis(dd[x][j],dd[y][k]);
				if(l>nsu){
					nx=dd[x][j];
					ny=dd[y][k];
					nsu=l;
				}
			}
		su[x]=nsu;
		dd[x][0]=nx;
		dd[x][1]=ny;
		fa[y]=x;
		writeln(su[x]);
	}
	return 0;
}

