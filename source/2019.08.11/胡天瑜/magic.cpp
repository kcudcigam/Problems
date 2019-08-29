#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int p=998244353;

long long n;
string s;

int power(int a,long long b)
{
	int ans=1;
	for(;b;b=b>>1)
	{
		if(b&1) ans=(long long)ans*a%p;
		a=(long long)a*a%p;
	}
	return ans;
}

long long calc(long long len,long long nn)
{
	long long beminused=power(26,nn);
	long long minuser=(len*25*power(26,nn-len-1))%p;
	minuser+=power(26,nn-len);
	minuser=minuser%p;
	beminused=beminused+p;
	long long ans=(beminused-minuser)%p;
	return ans;
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	cin>>s;
	if(n==s.length())
	{
		printf("%d\n",power(25,n));
	}
	else
	{
		long long slen=s.length();
		printf("%lld\n",calc(slen,n));
	}
	return 0;
}
