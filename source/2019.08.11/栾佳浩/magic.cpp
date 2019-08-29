#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
const int maxn=1000005;
const int mod=998244353;
char s[maxn];
ll ksm(ll a,ll x)
{
	ll re=1;
	while(x)
	{
		if(x&1)re=re*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return re;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",s);
	int len=strlen(s);
	if(1ll*len==n)
	{
		printf("%lld",ksm(26,n)-1);
		return 0;
	}
	printf("%lld",((ksm(26,n)-ksm(26,n-len-1)*len%mod*25%mod-ksm(26,n-len))%mod+mod)%mod);

	return 0;
 } 
