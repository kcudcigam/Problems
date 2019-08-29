#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[2000001];
long long n,len,s;
long long qpow(int a,int b,int m)
{
	long long r=1;
	while(b)
	{
		if(b%2)
			r=r*a%m;
		a=a*a%m;
		b/=2;
	}
	return r;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>a;
	len=strlen(a);
	s=(qpow(26,n,998244353)-(len+1)*qpow(26,n-len,998244353)+
	qpow(26,n-len-1,998244353)*len)%998244353;
	if(s<0)
		s+=998244353;
	cout<<s;
}
