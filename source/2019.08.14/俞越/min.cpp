#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
const LL inf=-1e17;
LL A,B,C,D;
int stk[M],tp,n,L[M],R[M],a[M];
LL fuck[M];
double calc(double x){
	return (double)((B+A*x)*x+C)*x+D;
} 
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
LL tg[M<<3],mx[M<<3];
void pushup(int x){
	mx[x]=max(mx[lc],mx[rc]);
}
void pushdown(int x){
	if (tg[x]==inf) return ;
	LL tmp=tg[x];
	tg[lc]=max(tmp,tg[lc]); tg[rc]=max(tmp,tg[rc]);
	mx[lc]=max(tmp,mx[lc]); mx[rc]=max(tmp,mx[rc]); 
	tg[x]=inf;
}
void build(int x,int l,int r){
	tg[x]=inf;	mx[x]=inf;
	if (l==r) return ;
	build(lc,l,mid); 
	build(rc,mid+1,r);
	pushup(x);
}
LL query(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return mx[x];
	pushdown(x);
	if (rr<=mid) return query(lc,l,mid,ll,rr);
	if (ll>mid) return query(rc,mid+1,r,ll,rr);
	return max(query(lc,l,mid,ll,mid),query(rc,mid+1,r,mid+1,rr));
}
void update(int x,int l,int r,int ll,int rr,LL d){
	if (l==ll && r==rr){
		tg[x]=max(tg[x],d);
		mx[x]=max(mx[x],d);
		return ;
	}
	pushdown(x);
	if (rr<=mid) update(lc,l,mid,ll,rr,d);
	else if (ll>mid) update(rc,mid+1,r,ll,rr,d);
	else update(lc,l,mid,ll,mid,d),update(rc,mid+1,r,mid+1,rr,d);
	pushup(x);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read(); A=read(); B=read(); C=read(); D=read();
	F(i,1,n){
		a[i]=read();
		fuck[i]=calc(a[i]);
	}
	stk[1]=tp=1; L[1]=1;
	for (int i=2;i<=n;i++){
		while (tp && a[stk[tp]]>a[i]) tp--;
		if (!tp) L[i]=1;
		else L[i]=stk[tp]+1;
		stk[++tp]=i;
	}
	stk[tp=1]=n; R[n]=n;
	for (int i=n-1;i>=1;i--){
		while (tp && a[stk[tp]]>=a[i]) tp--;
		if (!tp) R[i]=n;
		else R[i]=stk[tp]-1;
		stk[++tp]=i;
	}
	build(1,0,n);
	update(1,0,n,0,0,0);
	F(i,1,n){
		LL tmp=query(1,0,n,L[i]-1,i-1);
		update(1,0,n,i,R[i],tmp+fuck[i]);
	}
	cout<<query(1,0,n,n,n)<<"\n";
	return 0;
}
