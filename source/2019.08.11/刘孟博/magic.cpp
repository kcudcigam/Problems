#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const ll MOD=998244353;
ll n,ans,tmp,len;char c[MAXN];
inline ll qpow(ll a,ll b){
	ll res=1,base=a;
	while(b){
		if(b&1)res=res*base%MOD;
		base=base*base%MOD;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);scanf("%s",c+1);
	ans=qpow(26ll,n%(MOD-1));len=strlen(c+1),n=n-len;
	if(!n)printf("%lld",((ans-1ll)+MOD)%MOD);
	else{
		tmp=qpow(26ll,n)*(len+1)%MOD;
		tmp-=qpow(26ll,n-1)*len%MOD;
		ans=((ans-tmp)%MOD+MOD)%MOD;
		printf("%lld",ans);
	}
	return 0;
}
