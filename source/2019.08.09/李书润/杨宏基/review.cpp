#include<cstdio>
#include<iostream>
using namespace std;
long long p[1001],g[1001][1001],d[1001];
long long y,n,m;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	p[0]=1;
	for(int i=1;i<=61;i++)
		p[i]=p[i-1]*2;
	long long t=0;
	for(int i=0;i<=30;i++)
		if(p[i]==y)
			t=i;
	if(t)
	{
		n=t+2;
		m=n*(n-1)/2;
		printf("%lld %lld\n",n,m);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				printf("%d %d\n",i,j);
	}
	else
	{
		n=2;
		m=0;
		for(int i=61;i>=0;i--)
			if(p[i]<=y)
			{
				y-=p[i];
				t++;
				n+=i+1;
				m+=(i+2)*(i+1)/2;
				g[t][0]=i+2;
				g[t][1]=1;
				d[t]=n-1;
				for(int j=2;j<=i+2;j++)
					g[t][j]=n-j+1;
			}
		printf("%lld %lld\n",n,m+t);
		for(int i=1;i<=t;i++)
			for(int j=1;j<g[i][0];j++)
				for(int k=j+1;k<=g[i][0];k++)
				{
					long long u=g[i][j],v=g[i][k];
					if(u>v)
					{
						int temp=u;
						u=v;
						v=temp;
					}
					printf("%lld %lld\n",u,v);
				}
		for(int i=1;i<=t;i++)
			cout<<d[i]<<' '<<n<<endl;
	}
}
