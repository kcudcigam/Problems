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
int k,tot,nxt[400100],to[400100],head[400100],n,fa[200100][22],depth[200100],ans[200100],c[200100];
inline void addedge(int x,int y){
	nxt[++tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}
inline void add(int x,int y){
	addedge(x,y);
	addedge(y,x);
}
inline void dfs1(int x){
	for(int i=head[x];i;i=nxt[i])
		if(to[i]==fa[x][0])continue;
		else {
			depth[to[i]]=depth[x]+1;
			fa[to[i]][0]=x;
			dfs1(to[i]);
		}
}
inline void prepare(){
	F(i,1,20)
		F(j,1,n)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline void dfs2(int x){
	for(int i=head[x];i;i=nxt[i])if(to[i]!=fa[x][0]){dfs2(to[i]);ans[x]+=ans[to[i]];}
	if((ans[x]&1)!=c[x]&&depth[x]>=k){
		ans[x]++;
		int y=x;
		F(i,0,20)if((k>>i)&1)y=fa[y][i];
		ans[y]++;
	}
}
inline void solve(){
	tot=0;
	read(n);read(k);
	memset(ans,0,sizeof(ans));
	memset(fa,0,sizeof(fa));
	memset(to,0,sizeof(to));
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(c,0,sizeof(c));
	F(i,1,n-1){
		int x,y;
		read(x);read(y);
		add(x,y);
	}
	F(i,1,n)read(c[i]);
	F(i,1,n){int x;read(x);c[i]^=x;}
	depth[1]=1;
	dfs1(1);
	prepare();
	dfs2(1);
	F(i,1,n)if((ans[i]&1)!=c[i]){puts("No");return;}
	puts("Yes");
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;read(t);
	while(t--)solve();
	return 0;
}
