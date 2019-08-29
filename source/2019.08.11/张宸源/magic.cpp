#include<bits/stdc++.h>
#define gc() getchar()
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const int mod=998244353;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
	x*=f; 
}
ll __pow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)
		res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll n;
char s[1000050];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ll inv=__pow(26,mod-2);
	read(n);
	scanf("%s",s+1);
	int len=strlen(s+1);
	ll sum=1;
	ll u=__pow(26,(ll)n-len),v=1;
	ll ans=0;
	rep(i,0,len)
	{
		ll t=min(n-len,(ll)i);
		ans+=u*(v-t);
		ans%=mod;
		if(u!=1)
		{
			u=u*inv%mod;
			v=v*26%mod;
		}
	}
	ll Ans=__pow(26,n);
	if(len==n)
	{
		printf("%lld\n",(Ans-1+mod)%mod);
		return 0;
	}
	Ans=(Ans-ans+mod)%mod;
	printf("%lld\n",Ans);
	return 0;
}
/*
int:
999999999999999999
abcdefghijklmnopqrstuvwxyz

out:
130701488
*/

