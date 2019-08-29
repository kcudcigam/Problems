#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n;
long long a[100001];
long long sum[100001];
long long d;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) 
	{
		read(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int k=1;k<n;k++)
	{
		long long mx1=0,mx2=0;
		for(int i=1;i<=k;i++)
		for(int j=0;j<i;j++)
		mx1=max(mx1,sum[i]-sum[j]);
		
		for(int i=k+1;i<=n;i++)
		for(int j=k;j<i;j++)
		mx2=max(mx2,sum[i]-sum[j]);
		
		d=max(d,mx1+mx2);
	}
	cout<<d<<endl;
	return 0;
}

