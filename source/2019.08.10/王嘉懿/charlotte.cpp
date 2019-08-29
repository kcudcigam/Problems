#include<bits/stdc++.h>
using namespace std;
int t,n,t0,x0,yy0,t1,x1,yy1,jl;
template <typename T> void read(T & x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar())  x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    read(t);
    while(t--)
    {
    	int sf=0;
    	t0=0;x0=0;yy0=0;
    	read(n);
    	for(register int i=1;i<=n;i++)
    	{
    		read(t1);read(x1);read(yy1);
    		jl=abs(x1-x0)+abs(yy1-yy0);
    		if((t1-t0)<jl||(t1-t0-jl)%2==1)
    		{
    			sf=1;break;
			}
			x0=x1;
			yy0=yy1;
			t0=t1;
		}
		if(sf==1) puts("No");
		else puts("Yes");
	}
}
