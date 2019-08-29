#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long f[2001][2001][2],x[1000001];
long long n,a,b,c,d;
long long cal(long long u)
{
	long long r=a*u*u*u+b*u*u+c*u+d;
	return r;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>a>>b>>c>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		f[i][i][1]=cal(x[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(j==i)
				f[i][j][0]=x[j];
			else
				f[i][j][0]=min(x[j],f[i][j-1][0]);
		}
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			f[i][j][1]=cal(f[i][j][0]);
			for(int k=i;k<j;k++)
				f[i][j][1]=max(f[i][j][1],f[i][k][1]+f[k+1][j][1]);
		}
	cout<<f[1][n][1];
}
