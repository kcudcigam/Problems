#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000000+5
const ll HA=998244353;
char c[MAXN];
ll n,len;
ll qpow(ll a,ll x)
{
	ll ans=1,base=a;
	while(x>0)
	{
		if(x&1)
			ans=(ans*base)%HA;
		base=(base*base)%HA;
		x>>=1;
	}
	return ans;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d%s",&n,c);
	len=strlen(c);
	printf("%lld",((qpow(26,n))-((1LL*25*(len+1)+1)*qpow(26,n-len-1))%HA+HA)%HA);
	return 0;
}
