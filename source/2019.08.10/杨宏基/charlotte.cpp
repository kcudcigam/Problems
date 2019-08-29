#include<cstdio>
#include<iostream>
using namespace std;
int T,n,p,l,a,b,disx,disy,t,x,y;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		p=0;
		l=0;
		a=0;
		b=0;
		while(n--)
		{
			scanf("%d%d%d",&t,&x,&y);
			disx=x-a;
			disx*=(disx<0)?(-1):1;
			disy=y-b;
			disy*=(disy<0)?(-1):1;
			if(t-l<disx+disy||(t-l)%2!=(disx+disy)%2)
			{
				p=1;
				break;
			}
			a=x;
			b=y;
			l=t;
		}
		if(p)
			printf("No\n");
		else
			printf("Yes\n");
	}
}
