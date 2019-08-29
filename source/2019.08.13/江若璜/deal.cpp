#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005,M=20005,mod=1000000007;
ll n,X,f[M],d[N],a[N],b[N],c[N],ans,maxn;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	rd(n);rd(X);f[0]=d[0]=1;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
		maxn=max(maxn,a[i]);
	}
	for(ll i=n-1;i>=0;i--)
		for(ll j=X-1;j>=0;j--)
			if(f[j]>0)
				for(ll k=0;k<b[i]&&k*a[i]+j<X;k++)
					f[j+(k+1)*a[i]]=(f[j]+f[j+a[i]*(k+1)])%mod;
	for(ll i=n-1;i>=0;i--)
		for(ll j=X-1;j>=0;j--)
			if(d[j]>0)
				for(ll k=0;k<c[i]&&k*a[i]+j<X;k++)
					d[j+(k+1)*a[i]]=(d[j]+d[j+a[i]*(k+1)])%mod;
	for(ll i=X;i<X+maxn;i++) ans=(ans+(f[i]*d[i-X])%mod)%mod;
	wr(ans);puts("");
	return 0;
}
