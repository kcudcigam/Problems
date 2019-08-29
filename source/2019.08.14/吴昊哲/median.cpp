#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() 
{
    char c=getchar(); 
	int x=0; 
	for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10-'0'+c; 
	return x;
}
ll n,m,x,y,z,l1,r1,l2,r2;
ll a[5000000],b[5000000],c[5000000];
int ord;
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
    n=read();m=read();
    for(ll i=1;i<=n;i++)a[i]=read();
    for(ll i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=m;i++)
    {
    	ord=read();
    	if(ord==1)
    	{
    		x=read();y=read();z=read();
    		if(x==0)a[y]=z;
    		if(x==1)b[y]=z;
		}
		if(ord==2)
		{
			l1=read();r1=read();l2=read();r2=read();
			int tot=0;
			for(;l1<=r1;l1++)
			{
				tot++;c[tot]=a[l1];
			}
            for(;l2<=r2;l2++)
			{
				tot++;c[tot]=b[l2];
			}
			sort(c+1,c+tot+1);
			cout<<c[tot/2+1]<<endl;
		}
	}
	return 0;
}
