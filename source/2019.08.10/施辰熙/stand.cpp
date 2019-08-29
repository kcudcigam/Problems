#include<bits/stdc++.h>
using namespace std;
long long a[100],b[1000][100],n,m,x[1000],y[1000],sum,Max,t[1000],Maxi,sum1,Max2;
long long f[1000];
bool sp;
long long calc()
{
	sum=0;
	for (int i=1;i<=m;i++)
	{
		for (int k=1;k<=5;k++)
		{
			sum+=b[t[i]][k]*a[k];
		}
	}
	return sum;
}
void dfs(int dep)
{
	if (dep>n)
	{
		Max=max(Max,calc());
	}
	else
	{
		for (int i=x[dep];i<=y[dep];i++)
		{
			t[i]++;
			dfs(dep+1);
			t[i]--;
		}
	}
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	sp=true;
	for (int i=1;i<=5;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=40;i++)
	{
		b[i][1]=i;
		for (int j=2;j<=5;j++)
		{
			b[i][j]=b[i][j-1]*i;
		}
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		for (int j=x[i];j<=y[i];j++)
			f[j]++;
	}
	if (m<=5&&n<=35||n<=15&&m<=15)
	{
		Max=-INT_MAX;
		dfs(1);
		cout << Max << endl;
		exit(0);	
	}
	for (int i=1;i<=n;i++)
	{
		Max=-INT_MAX;Maxi=0;sum=0;sum1=0;Max2=0;
		for (int p=x[i];p<=y[i];p++)
		{
			sum=0;sum1=0;
			for (int k=1;k<=5;k++)
			{
				sum+=b[t[p]+1][k]*a[k];
				sum1+=b[t[p]][k]*a[k];
			}
			if (sum-sum1>Max)
			{
				Max=sum-sum1;
				Maxi=p;
			}
			else
			if (sum-sum1==Max&&f[p]>Max2)
			{
				Maxi=p;
				Max2=f[p];
			}
		}
		t[Maxi]++;
	}
	sum=0;
	for (int i=1;i<=m;i++)
	{
		for (int k=1;k<=5;k++)
		{
			sum+=b[t[i]][k]*a[k];
		}
	}
	cout << sum << endl;
	return 0;
}
	
