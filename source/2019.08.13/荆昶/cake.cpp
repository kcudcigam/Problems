#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int a[305][305];
int f(int n,int m)
{
	if(n==1&&m==1)
	{
		return 1;
	}
	unsigned long long s=0;
	for(int i=1;i<n;i++)
	{
		if(!a[i][m])
		{
			a[i][m]=a[m][i]=f(i,m);
		}
		if(!a[n-i][m])
		{
			a[n-i][m]=a[m][n-i]=f(n-i,m);
		}
		s+=a[i][m]*a[n-i][m];
		s%=MOD;
	}
	for(int i=1;i<m;i++)
	{
		if(!a[n][i])
		{
			a[n][i]=a[i][n]=f(n,i);
		}
		if(!a[n][m-i])
		{
			a[n][m-i]=a[m-i][n]=f(n,m-i);
		}
		s+=a[n][i]*a[n][m-i];
		s%=MOD;
	}
	return s;
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<f(n,m);
	return 0;
}

