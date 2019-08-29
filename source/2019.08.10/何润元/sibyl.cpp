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
int cnt,cnt2,nxt[2*N],nxt2[2*N],to[2*N],to2[2*N],head[2*N],head2[2*N],ans[N],du[N],fa[N],now[N],f2[N],f3[N];
inline void addedge(int x,int y){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
}
inline void addedge2(int x,int y){
	nxt2[++cnt2]=head2[x];
	to2[cnt2]=y;
	head2[x]=cnt2;
}
inline void add(int x,int y){
	addedge(x,y);
	addedge(y,x);
}
inline void dfs(int x){	for(int i=head[x];i;i=nxt[i])if(fa[x]!=to[i]){fa[to[i]]=x;dfs(to[i]);}}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q;read(n);read(m);read(q);
	F(i,1,m){
		int x,y;read(x);read(y);
		add(x,y);
		du[x]++;
		du[y]++;
	}
	if(n<=3000&&m<=3000&&q<=3000){
		F(j,1,q){
			int opt;read(opt);
			if(opt){
				int x,y;read(x);read(y);
				ans[x]+=y;
				for(int i=head[x];i;i=nxt[i])ans[to[i]]+=y;
			}
			else{
				int x;read(x);
				writeln(ans[x]);
			}
		}
		return 0;
	}
	if(n==m+1){
		dfs(1);
		F(i,1,q){
			int opt;read(opt);
			if(opt){
				int x,y;read(x);read(y);
				now[x]+=y;
				ans[fa[x]]+=y;
			}
			else {
				int x;read(x);
				writeln(ans[x]+now[fa[x]]);
			}
		}
		return 0;
	}
	int f=1;
	F(i,2,n)if(du[i]>10){f=0;break;}
	if(f){
		int no=0;
		for(int i=head[1];i;i=nxt[i])f2[to[i]]=1;
		F(j,1,q){
			int opt;read(opt);
			if(opt){
				int x,y;read(x);read(y);
				ans[x]+=y;
				if(x==1)no+=y;
				else for(int i=head[x];i;i=nxt[i])ans[to[i]]+=y;
			}
			else {
				int x;read(x);
				if(f2[x])writeln(ans[x]+no);
				else writeln(ans[x]);
			}
		}
		return 0;
	}
	int k=sqrt(2*m);
	F(i,1,n)
		if(du[i]>k){
			f3[i]=1;
			for(int j=head[i];j;j=nxt[j])
				if(du[to[j]]>k)addedge2(i,to[j]);
		}
	F(j,1,q){
		int opt;read(opt);
		if(opt){
			int x,y;read(x);read(y);
			if(f3[x]){
				now[x]+=y;
				ans[x]+=y;
			}
			else {
				ans[x]+=y;
				for(int i=head[x];i;i=nxt[i])ans[to[i]]+=y;
			}
		}
		else {
			int x;read(x);
			if(f3[x]){
				int an=0;
				for(int i=head2[x];i;i=nxt2[i])an+=now[to[i]];
				writeln(an+ans[x]);
			}
			else {
				int an=0;
				for(int i=head[x];i;i=nxt[i])an+=now[to[i]];
				writeln(an+ans[x]);
			}
		}
	}
	return 0;
}

