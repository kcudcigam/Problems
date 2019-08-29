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
int n,m;
int cnt,nxt[2*N],to[2*N],val[2*N],head[N],fa[N],father[N][21],mx[N][21],depth[N];
struct yy{
	int x,y,w;
}edge[N];
inline bool cmp(yy a,yy b){return a.w<b.w;}
inline int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
inline void addedge(int x,int y,int w){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	val[cnt]=w;
	head[x]=cnt;
}
inline void add(int x,int y,int w){
	addedge(x,y,w);
	addedge(y,x,w);
}
inline void kruskal(){
	sort(edge+1,edge+m+1,cmp);
	F(i,1,n)fa[i]=i;
	F(i,1,m){
		int x=get(edge[i].x),y=get(edge[i].y);
		if(x==y)continue;
		fa[x]=y;
		add(edge[i].x,edge[i].y,edge[i].w);
	}
}
inline void make_tree(int x){
	for(int i=head[x];i;i=nxt[i])
		if(father[x][0]!=to[i]){
			father[to[i]][0]=x;
			mx[to[i]][0]=val[i];
			depth[to[i]]=depth[x]+1;
			make_tree(to[i]);
		}
}
inline void pre_beizeng(){
	F(i,1,20)
		F(j,1,n){
			father[j][i]=father[father[j][i-1]][i-1];
			mx[j][i]=max(mx[j][i-1],mx[father[j][i-1]][i-1]);
		}
}
inline void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
inline int lca(int x,int y){
	int ans=0;
	if(depth[x]>depth[y])swap(x,y);
	DF(i,20,0)if(depth[father[y][i]]>=depth[x]){checkmax(ans,mx[y][i]);y=father[y][i];}
	if(x==y)return ans;
	DF(i,20,0)if(father[y][i]!=father[x][i]){checkmax(ans,max(mx[x][i],mx[y][i]));x=father[x][i];y=father[y][i];}
	checkmax(ans,max(mx[x][0],mx[y][0]));
	return ans;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int q;read(n);read(m);read(q);
	F(i,1,m){
		read(edge[i].x);
		read(edge[i].y);
		read(edge[i].w);
	}
	kruskal();
	F(i,1,n)if(fa[i]==i)make_tree(i);
	pre_beizeng();
	F(i,1,q){
		int x,y;read(x);read(y);
		if(get(x)!=get(y))puts("-1");
		else writeln(lca(x,y));
	}
	return 0;
}

