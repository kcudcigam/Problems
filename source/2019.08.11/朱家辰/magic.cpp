#include<bits/stdc++.h>
#define maxn 1000010
#define inf 0x3f3f3f3f
#define mod 998244353
#define ll long long
using namespace std;
ll n,m,ans;
char s[maxn];
ll ksm(ll x,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1) ans=ans*x%mod;
		k>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	scanf("%s",s);
	m=strlen(s);
	if(m==n)
	{
		printf("%lld",(ksm(26,n)-1+mod)%mod);
		return 0;
	}
	ans=(ans+(m+1)*ksm(26,n-m))%mod;
	ans=((ans-m*ksm(26,n-m-1))%mod+mod)%mod;
	ll tmp=ksm(26,n);
	ans=(tmp-ans)%mod;
	ans=(ans+mod)%mod;
	printf("%lld",ans);
	return 0;
}

