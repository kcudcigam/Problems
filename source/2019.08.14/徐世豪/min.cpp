#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,a,b,c,d;
ll x[200009];
ll f[200009];
inline ll find(ll k){
	ll t=k;
	ll ans=d;
	ans+=c*t;
	t*=k;
	ans+=b*t;
	t*=k;
	ans+=a*t;
	return ans;
}
inline ll ss(ll l,ll r){
	ll ans=0x7fffffff;
	for(int i=l;i<=r;i++)
		ans=min(ans,x[i]);
	return ans;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
	f[1]=find(x[1]);
	for(int i=2;i<=n;++i)
		for(int j=1;j<i;j++)
			f[i]=max(f[i],f[j]+find(ss(j+1,i)));
	printf("%lld",f[n]);
	return 0;
}
