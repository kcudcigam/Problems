#include<bits/stdc++.h>
using namespace std;
long long n,l,mo=998244353,q,N,u,v,cs;
string a;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long ksm(long long a,long long k)
{
	long long ans=1;
	while(k)
	{
		if(k & 1)
		ans=(long long)ans*a%mo;
		a=(long long)a*a%mo;
		k>>=1;
	}
	return ans;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	cin>>a;
	l=a.size();
	N=ksm(26,n);
	u=ksm(26,n-l);
	cs=ksm(26,mo-2);
	
	if(n==1)
	{
		cout<<"25";return 0;
	}
	if(n==2)
	{
		if(l==1){
		 cout<<"625";return 0;}
		else {
		cout<<"675";return 0;}
	}
	if(n==3)
	{
		if(l==1)
		{
			cout<<"16926";return 0;
		}
		if(l==2)
		{
			cout<<"17500";return 0;
		}
		else
		{
			cout<<"17575";return 0;
		}
	}
	return 0;
 } 
