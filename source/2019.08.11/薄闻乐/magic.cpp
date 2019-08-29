#include<bits/stdc++.h>
using namespace std;
long long n,t;
char ch;
long long cm(long long cs,long long s)
{
	long long x=0;
	if(cs==1)
	return s;
	if(cs%2==0)
	{
		x=cm(cs/2,26*s%998244353);
		return x*x%998244353;
	}
	else {
		x=cm(cs/2,26*s%998244353);
		return x*x*26%998244353;
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	ch=getchar();
	ch=getchar();
	while('a'<=ch&&'z'>=ch)
	{
		t++;
		ch=getchar();
	}
	cout<<cm(n,1)-cm(n-t,26)*(n-t+1)%998244353+1<<endl;
	return 0;
}
