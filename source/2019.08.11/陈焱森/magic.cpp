#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const ll mod=998244353ll;

ll p[1000000],sum[1000000];

ll qp(ll a,ll b) {
	ll res=1ll;
	while(b) {
		if(b&1ll)res=res*a%mod;
		a=a*a%mod;
		b>>=1ll;
	}
	return res;
}
ll c(ll a,ll b) {
	return p[b]*qp(p[a]*p[b-a]%mod,mod-2)%mod;
}

char s[1000000];

int main(void) {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	int n;
	cin>>n>>s;
	p[0]=1ll;
	for(ll i=1;i<=998244353ll;++i)
		p[i]=p[i-1]*i%mod;
	ll len=strlen(s);
	for(int i=len+1;i<=n;++i) {
		sum[i]=(len-1)*c(2ll,i-len+1)-sum[i-1];
	}
	
	fclose(stdin);
	fclose(stdout);
} 
