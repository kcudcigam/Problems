#include<bits/stdc++.h>
using namespace std;
bool bk[251];
int shp[10000001];
int g1,g2,g3,g4,g5;
long long s;
long long g(int x)
{
	return g1*x+g2*x*x+g3*x*x*x+g4*x*x*x*x+g5*x*x*x*x*x;
}
struct pp{
	int x;
	int y;
}a[251];
int d,d1,bj;
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&g1,&g2,&g3,&g4,&g5);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	while(bj<n)
	{
		d=0;
		for(int j=1;j<=n;j++)
		if(!bk[j])
		for(int i=a[j].x;i<=a[j].y;i++)
		shp[i]++;
		for(int i=1;i<=m;i++)
		{
			if(d<shp[i])
			{
				d=shp[i];
				d1=i;
			}
			shp[i]=0;
		}
		
		bj+=d;
		s+=g(d);
		
		for(int i=1;i<=n;i++)
		if(a[i].x<=d1&&a[i].y>=d1)
		bk[i]=1;
		
	}
	cout<<s;
	return 0;
}

