#include <iostream>
#include <cstdio>
#include <cstring>

const int mod=998244353;

long long n,ans;

inline long long cal(long long x)
{
	if (x==1)
		return 26;
	if (x&1)
	{
		long long a=cal(x/2)%mod;
		return (a*a%mod)*26%mod;
	}
	else
	{
		long long a=cal(x/2)%mod;
		return a*a%mod;
	}
}

using namespace std;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	string s;
	
	scanf("%lld\n",&n);
	getline(cin,s);

	long long len=s.size();
	if (n==len)
	{
		ans=(cal(n)-1)%mod;
		if (ans<0)
			ans+=mod;
		printf("%lld\n",ans);
		return 0;
	}
	else
	{
		
		long long rest=n-len;
		ans=((cal(n))%mod-(len+1)*cal(rest)%mod+len)%mod;
		if (ans<0)
			ans+=mod;
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}











