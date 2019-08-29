#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int T,n,ta,tb,xa,xb,ya,yb;

int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		bool flag=true;
		scanf("%d",&n);
		scanf("%d%d%d",&ta,&xa,&ya);
		if (n==1)
		{
			if (xa+ya<=ta && (xa+ya+ta)%2==0)
			{
				puts("Yes");
				continue;
			}
			else 
			{
				puts("No");
				continue;
			}
		}
		for (register int i=1;i<n;++i)
		{
			scanf("%d%d%d",&tb,&xb,&yb);
			int tt=tb-ta,d=abs(xb-xa)+abs(yb-ya); 
			if (tt<d || (tt+d)&1)
			{
				flag=false;
				break;				
			}
			ta=tb;
			xa=xb;
			ya=yb;
		}
		if (flag)
			puts("Yes");
		else 
			puts("No");
	}
	return 0;
}



