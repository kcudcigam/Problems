#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353ll;
ll pow(ll a,ll b,ll p){
	ll ans=1;
	for (;b;b>>=1){
		if (b&1)ans=ans*a%p;
		a=a*a%p;
	}
	return ans%p;
}
ll calc(ll k){
	if (k==0) return 1%MOD;
	if (k==1) return 26%MOD;
	if (k%2){
		ll ret=calc((k+1)/2-1)%MOD;
		return (ret%MOD+ret%MOD*pow(26,(k+1)/2,MOD)%MOD)%MOD;
	}
	else{
		return (calc(k-1)%MOD+pow(26,k,MOD)%MOD)%MOD;
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll n;cin>>n;
	string s;cin>>s;
	ll m=s.size();
	ll ans=(pow(26,n,MOD)%MOD-pow(26,n-m,MOD)*(m+1)%MOD+calc(n-m-1)%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}
