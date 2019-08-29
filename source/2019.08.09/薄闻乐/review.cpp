#include<bits/stdc++.h>
using namespace std;
long long n,y,a[20000],t;
long long read()
{
	long long f=1,x=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
long long check(long long t,long long dep)
{
	if(t==1)
	return dep;
	if(t%2!=0)
	return 0;
	
	return check(t/2,dep+1);
}
long long cf(long long x)
{
	if(x==1)
	return 2;
	return 2*cf(x-1);
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	y=read();
	if((n=check(y,0)))
	{
		cout<<n+2<<' '<<(n+1)*(n+2)/2<<endl;
		for (long long i=1;i<=n+2;i++)
		{
			for (long long j=i+1;j<=n+2;j++)
			cout<<i<<' '<<j<<endl;
		}
		return 0;
	}
	if(y==1)
	{
		cout<<2<<' '<<1<<endl;
		cout<<1<<' '<<2<<endl;
		return 0;
	}
	n=1;
	t=1;
	while(n<=y)
	{
		n*=2;
		t++;
	}
	a[t]=1;
	a[t+1]=1;
	for (long long i=t-1;i>=1;i--)
	a[i]=a[i+1]*2;
	cout<<t+1<<' ';
	long long s=1,ans=1;
	for (long long i=t;i>=1;i--)
	{
		if(s+a[i]>y)
		break;
		s+=a[i];
	}
	ans=max(t*(t+1)/2+y-cf(t-1),(t-1)*t/2+2);
	cout<<ans<<endl;
	s=t+1;
	while(ans>0)
	{
		if(ans<=t+1-s)
		break;
		cout<<1<<' '<<s<<endl;
		for (long long j=s+1;j<=t+1;j++)
		cout<<s<<' '<<j<<endl;
		s--;
		ans=ans-1-t+s;
	}
	if(ans!=0)
	{
		cout<<1<<' '<<2<<endl;
		for (long long i=1;i<ans;i++)
		cout<<2<<' '<<t+2-i<<endl;
	}
	return 0;
}
