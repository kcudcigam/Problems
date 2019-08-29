#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"-------------"<<endl;

inline LL read(){
	LL x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL INF = 1e16;
const LL MAXN = 200010;

LL sta[MAXN+1],top;
LL N; LL a[MAXN+1];
LL tag[MAXN<<2],mx[MAXN<<2],F[MAXN<<2];
LL A,B,C,D; LL f[MAXN+1];

inline void pushdown(LL rt){
	if(tag[rt]==-INF) return ;
	mx[rt<<1]=F[rt<<1]+tag[rt];
	mx[rt<<1|1]=F[rt<<1|1]+tag[rt];
	tag[rt<<1]=tag[rt]; tag[rt<<1|1]=tag[rt];
	tag[rt]=-INF; return ;
}
inline LL Calc(LL x){ return A*x*x*x+B*x*x+C*x+D; }
inline void update(LL rt){ F[rt]=max(F[rt<<1],F[rt<<1|1]); mx[rt]=max(mx[rt<<1],mx[rt<<1|1]); }
inline void mdf(LL rt,LL l,LL r,LL L,LL R,LL x){
	if(L<=l&&R>=r){
		mx[rt]=F[rt]+Calc(x);
		tag[rt]=x; return ;
	} LL mid=(l+r)>>1; pushdown(rt);
	if(L<=mid) mdf(rt<<1,l,mid,L,R,x);
	if(R>mid) mdf(rt<<1|1,mid+1,r,L,R,x);
	update(rt); return ;
}
inline void Update(LL rt,LL l,LL r,LL k,LL fa){
	if(l==r){ F[rt]=fa; return ; }
	LL mid=(l+r)>>1; pushdown(rt);
	if(k<=mid) Update(rt<<1,l,mid,k,fa);
	else Update(rt<<1|1,mid+1,r,k,fa); update(rt);
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	N=read(),A=read(),B=read(),C=read(),D=read();
	for(LL i=0;i<(MAXN<<2);i++) tag[i]=-INF,mx[i]=F[i]=-INF;
	for(LL i=1;i<=N;i++) a[i]=read(); sta[++top]=0;
	Update(1,1,N,1,0);
	for(LL i=1;i<=N;i++){
		while(top&&a[sta[top]]>=a[i]) --top;
		mdf(1,1,N,sta[top]+1,i,a[i]); f[i]=mx[1];
		if(i!=N) Update(1,1,N,i+1,f[i]); sta[++top]=i;
	} printf("%lld\n",f[N]);
	return 0;
}

