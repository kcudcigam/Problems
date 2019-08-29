#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const p=998244353;
char s[2000001];
ll pw(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=p;
		x*=x;
		x%=p;
		y/=2;
	}
	return ans;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ll n;
	cin>>n;
	cin>>s;
	ll t=strlen(s);
	if(n==t)cout<<(pw(26,n)-1+p)%p;
	else cout<<(((pw(26,n)-((t+1)*pw(26,n-t))%p+t*pw(26,n-t-1)%p)%p+p)%p);
	return 0;
}
