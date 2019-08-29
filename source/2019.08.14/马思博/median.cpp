#include<bits/stdc++.h>
using namespace std;

int ri() 
{
    char c=getchar(); int x=0; 
	for(;c<'0'||c>'9'; c=getchar());
    for(;c>='0'&&c<='9';c=getchar()) 
	    x=x*10-'0'+ c; 
	return x;
}

int a[1005],b[1005];

int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;n=ri();m=ri();
	for(int i=1;i<=n;i++) a[i]=ri();
	for(int i=1;i<=n;i++) b[i]=ri();
	int  sa,sb,ea,eb,x,y,z,p;
	while(m--)
	{
		p=ri();
		if(p==1)
		{
			x=ri();y=ri();z=ri();
			if(x==0) a[y]=z;
			if(x==1) b[y]=z;
		}
		if(p==2)
		{
			sa=ri();ea=ri();sb=ri();eb=ri();
			int mid=(ea-sa+eb-sb+3)/2,flag;
			//cout<<mid<<" ";
			while(mid--)
			{
				if(a[sa]<=b[sb]&&sa<=ea) sa++,flag=1;
				else if(b[sb]<a[sa]&&sb<=eb) sb++,flag=2;
			}
			if(flag==1) cout<<a[sa-1]<<endl;
			if(flag==2) cout<<b[sb-1]<<endl;
		}
	}
	return 0;
}

