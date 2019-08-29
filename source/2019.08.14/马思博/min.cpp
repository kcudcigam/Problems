#include<bits/stdc++.h>
using namespace std;

int ri() 
{
    char c=getchar(); long long x=0; 
	for(;c<'0'||c>'9'; c=getchar());
    for(;c>='0'&&c<='9';c=getchar()) 
	    x=x*10-'0'+ c; 
	return x;
}

int fx[10],a[200005];

int f(int x)
{
	long long sum=0,cnt;
	for(int i=1;i<=4;i++)
	{
		cnt=fx[i];
		for(int j=1;j<=4-i;j++) cnt*=x;
		sum+=cnt;
	}
	return sum;
}

int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n,flag=0;n=ri();
	for(int i=1;i<=4;i++) 
	{
	   fx[i]=ri();
	   if(fx[i]<0) flag=1;
    }
	for(int i=1;i<=n;i++) a[i]=ri();
	long long ans=0;
	if(flag==0)
	{
		for(int i=1;i<=n;i++) 
		if(a[i]>0) ans+=f(a[i]);
		cout<<ans;
		return 0;
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	if(a[i]<0) ans+=f(a[i]);
	}
	if(ans==0) ans+=f(a[1]);
	cout<<ans;
	return 0;
}

