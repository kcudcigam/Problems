#include<bits/stdc++.h>
using namespace std;
int ri()
{
	char c = getchar();
	int x = 0;
	for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar())
		x = x * 10 - '0' + c;
	return x;
}
long long n,m,a[500010],b[500010],c[500010];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	
	n=ri();m=ri();
	for(int i=1;i<=n;i++)
		a[i]=ri();
	for(int i=1;i<=n;i++)
		b[i]=ri();
	
	for(int i=1;i<=m;i++)
	{
		int f;
		f=ri();
		if(f==1)
		{
			int x,y,z;
			x=ri();y=ri();z=ri();
			if(x)
				b[y]=z;
			else
				a[y]=z;
		}
		else
		{
			int la,ra,lb,rb,num;
			la=ri();ra=ri();lb=ri();rb=ri();
			num=ra-la+rb-lb+2;
			memset(c,0,sizeof(c));
			merge(a+la,a+ra+1,b+lb,b+rb+1,c);
			printf("%lld\n",c[num/2]);
		}
	}
	
	return 0;
}

