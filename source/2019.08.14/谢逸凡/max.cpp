#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
#define N 100005
using namespace std;
int p=1e9+7; 
ll qpow(ll y,ll z){
	ll ans=1;
	for(;z;z>>=1){
		if(z&1) y=y*y%p;
		ans=ans*y%p;
	}
	return ans*2;
}
ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,m,q;
ll sum;
ll x[N],y[N],P[N];
int main(){
//	printf("%lld\n",qpow(2,5));
    freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=ip(),m=ip();
	rep(i,1,n) x[i]=ip(),y[i]=ip(),P[i]=ip();
	while(m--){
		int l=ip(),r=ip();
		ll ans1=0,ans=0;
		rep(j,l,r){
			rep(i,1,n) ans1+=y[i]*qpow(P[i],p-2),ans1%=p;
			ans=max(ans,ans1);
		}
		sum=(sum+ans)%p;
	}
	sum=sum*qpow(n,p-2)%p;
	printf("%lld",sum);
	return 0;
}

