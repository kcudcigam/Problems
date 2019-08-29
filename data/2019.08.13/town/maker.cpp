#include<bits/stdc++.h>
using namespace std;
namespace Base{
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	int read(){
		int f=1,g=0;char ch=getchar();
   		for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
    	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
    	return f*g;
	}
	int getrand(){return INF&(rand()*19260817+rand()*23333+rand());}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;
namespace filename_maker{
	void pushid(char *ch,int x){
		if (x/10) pushid(ch,x/10);
		ch[strlen(ch)]=x%10+'0';
	}
	void push(char *ch,char *s){for (unsigned i=0;i<strlen(s);i++) ch[strlen(ch)]=s[i];}
}
using namespace filename_maker;
namespace input_maker{
	const int N=300005;
	int n,fl,m1,m2,a[N],b[N],u[N],v[N];
	void make_input(){
		srand(time(0));
		cerr<<"input n fl m1 m2"<<endl;
		n=read();fl=read();
		m1=read();m2=read();
		printf("%d\n",n);
		int cnt=0;
		for (int i=1;i<=n;i++) a[i]=i,b[i]=i;
		for (int i=2;i<=m1;i++){u[++cnt]=i-1;v[cnt]=i;}
		for (int i=m1+1;i<=m1+m2;i++){u[++cnt]=m1;v[cnt]=i;}
		for (int i=m1+m2+1;i<=n;i++){u[++cnt]=getrand()%(i-1)+1;v[cnt]=i;}
		if (fl) {random_shuffle(a+1,a+n+1);random_shuffle(b+1,b+n);}
		for (int i=1;i<n;i++) printf("%d %d\n",a[u[b[i]]],a[v[b[i]]]);
	}
};
namespace output_maker{

const int N=300005;
int n,fr[N],depth[N],fa[N][20],u[N],v[N];
vector<int> e[N];
struct node{int x,y;}a[N];
int lca(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=18;i>=0;i--) if (depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--) if (depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	for (int i=18;i>=0;i--)
	if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return depth[x]+depth[y]-depth[lca(x,y)]*2;}
node operator+(node a,node b){
	static int f[4];
	f[0]=a.x,f[1]=a.y,f[2]=b.x,f[3]=b.y;
	int x,y,d=-1;
	for (int i=0;i<4;i++)
	for (int j=i+1;j<4;j++){
		int t=dis(f[i],f[j]);
		if (t>d){d=t;x=f[i];y=f[j];}
	}
	return (node){x,y};
}
void build(int x,int fath){
	depth[x]=depth[fath]+1;fa[x][0]=fath;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[x])
	if (y!=fath) build(y,x);
}
int find(int x){return (x==fr[x]) ? x : fr[x]=find(fr[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	a[x]=a[x]+a[y];fr[y]=x;
}
int make_output(){
	n=read();
	for (int i=1;i<=n;i++) {a[i]=(node){i,i};fr[i]=i;e[i].clear();}
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	build(1,0);
	for (int i=1;i<n;i++){
		merge(u[i],v[i]);
		int t=find(u[i]);
		printf("%d\n",dis(a[t].x,a[t].y));
	}
	return 0;
}

};
int l,r;
char I[10]=".in",O[10]=".out";
char ch[50],inp[50],oup[50];
int main(){
	cerr<<"filename:"<<endl;
	scanf("%s",ch);
	cerr<<"l - r"<<endl;
	scanf("%d %d",&l,&r);
	for (int i=l;i<=r;i++){
		memcpy(inp,ch,50);memcpy(oup,ch,50);
		filename_maker :: pushid(inp,i);
		filename_maker :: pushid(oup,i);
		filename_maker :: push(inp,I);
		filename_maker :: push(oup,O);
		cerr<<inp<<endl;
		
		freopen(inp,"w",stdout);
		input_maker :: make_input();
		
		freopen(oup,"w",stdout);
		freopen(inp,"r",stdin);
		output_maker :: make_output();
		
		freopen("CON","r",stdin);
	}
	return 0;
}
