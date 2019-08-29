#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200010;

long long y;
struct Edge
{
	int u,v;
}E[MAXN];
int countedge=0;

int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&y);
	long long coy=y;
	if(y<=1000000001)
	{
		int startpos=0;
		for(int i=1;i<=31;++i)
		{
			if((1<<i)>y)
			{
				startpos=i-1;
				break;
			}
		}
		int prerealpos=32-startpos;
		for(int i=prerealpos;i<=30;++i)
		{
			for(int j=0;j<=1;++j)
			{
				E[++countedge].u=2*i+j;E[countedge].v=2*(i+1);
				E[++countedge].u=2*i+j;E[countedge].v=2*(i+1)+1;
			}
		}
		E[++countedge].u=62;E[countedge].v=64;
		E[++countedge].u=63;E[countedge].v=64;
		if(coy&1)
		{
			E[++countedge].u=1;E[countedge].v=64;
		}
		for(int i=1;i<=startpos;++i)
		{
			if(coy&(1<<i))
			{
				int reverse=32-i;
				E[++countedge].u=1;E[countedge].v=2*reverse;
				E[++countedge].u=1;E[countedge].v=2*reverse+1;
			}
		}
		printf("64 %d\n",countedge);
		for(int i=1;i<=countedge;++i)
		{
			printf("%d %d\n",E[i].u,E[i].v);
		}
	}
	else
	{
		int startpos=0;
		for(int i=1;i<=62;++i)
		{
			if((1ll*1<<i)>y)
			{
				startpos=i-1;
				break;
			}
		}
		int prerealpos=63-startpos;
		for(int i=prerealpos;i<=62;++i)
		{
			for(int j=0;j<=1;++j)
			{
				E[++countedge].u=2*i+j;E[countedge].v=2*(i+1);
				E[++countedge].u=2*i+j;E[countedge].v=2*(i+1)+1;
			}
		}
		E[++countedge].u=126;E[countedge].v=128;
		E[++countedge].u=127;E[countedge].v=128;
		if(coy&1)
		{
			E[++countedge].u=1;E[countedge].v=128;
		}
		for(int i=1;i<=startpos;++i)
		{
			if(coy&(1<<i))
			{
				int reverse=64-i;
				E[++countedge].u=1;E[countedge].v=2*reverse;
				E[++countedge].u=1;E[countedge].v=2*reverse+1;
			}
		}
		printf("128 %d\n",countedge);
		for(int i=1;i<=countedge;++i)
		{
			printf("%d %d\n",E[i].u,E[i].v);
		}
	}
	return 0;
}

