#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 200005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll N,A,B,C,D,a[maxn],mna[maxn<<2],dp[maxn];
ll mndp[maxn<<2];

inline ll read(){
	ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline void pushup(ll k){mna[k]=min(mna[k<<1],mna[k<<1|1]);}
inline void build(ll l,ll r,ll k){
	if(l==r){mna[k]=a[l];return;}
	ll mid=(l+r)>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	pushup(k); return;
}
inline ll query(ll x,ll y,ll l,ll r,ll k){
	if(x<=l && r<=y) return mna[k];
	ll mid=(l+r)>>1,res=inf;
	if(x<=mid) res=min(res,query(x,y,l,mid,k<<1));
	if(y>mid) res=min(res,query(x,y,mid+1,r,k<<1|1));
	return res;
}

inline void pushup1(ll k){mndp[k]=max(mndp[k<<1],mndp[k<<1|1]);}
inline ll query1(ll x,ll y,ll l,ll r,ll k){
	if(x<=l && r<=y) return mndp[k];
	ll mid=(l+r)>>1,res=-inf;
	if(x<=mid) res=max(res,query1(x,y,l,mid,k<<1));
	if(y>mid) res=max(res,query1(x,y,mid+1,r,k<<1|1));
	return res;
}
inline void upd1(ll p,ll x,ll l,ll r,ll k){
	if(l==r){mndp[k]=x;return;}
	ll mid=(l+r)>>1;
	if(p<=mid) upd1(p,x,l,mid,k<<1);
	else upd1(p,x,mid+1,r,k<<1|1);
	pushup1(k); return;
}

inline ll f(ll x){return A*x*x*x+B*x*x+C*x+D;}

inline ll find(ll x){
	ll l=1,r=x,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(query(mid,x,1,N,1)==a[x]) ans=mid,r=mid-1;
		else l=mid+1;
	}	
	return ans;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	N=read(),A=read(),B=read(),C=read(),D=read();
	for(ll i=1;i<=N;i++) a[i]=read();
	memset(dp,-63,sizeof(dp));
	build(1,N,1),dp[0]=0;
	if(N<=1000){	
		for(ll i=1;i<=N;i++)
			for(ll j=i-1;j>=0;j--)
				dp[i]=max(dp[i],dp[j]+f(query(j+1,i,1,N,1)));
		printf("%lld\n",dp[N]);
	}
	else{
		for(ll i=1;i<=N;i++){
			ll pos=find(i); 
			dp[i]=max(pos-2<0?-inf:dp[pos-2],query1(pos-1,i,1,N,1)+f(a[i]));
			upd1(i,dp[i],1,N,1);
		}
		printf("%lld\n",dp[N]);
	}
	return 0;
}

