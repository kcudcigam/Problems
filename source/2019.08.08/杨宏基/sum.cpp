#include<cstdio>
#include<iostream>
using namespace std;
long long a[200001],g[200001],d[200001];
long long n,r,s;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	r=-1e9;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		r=max(r,s);
		g[i]=r;
		if(s<0)
			s=0;
	}
	r=-1e9;
	s=0;
	for(int i=n;i>=1;i--)
	{
		s+=a[i];
		r=max(r,s);
		d[i]=r;
		if(s<0)
			s=0;
	}
	r=-1e9;
	for(int i=1;i<n;i++)
		r=max(r,g[i]+d[i+1]);
	cout<<r;
}
