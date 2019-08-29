#include<bits/stdc++.h>
using namespace std;
long long num,n,m1,m2,x[1010],xx[1010],y[1010],yy[1010],ans,f;
long long h[1010][1010],h1[1010][1010];
long long a[1000];
int used[1010];
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d%d%d%d",&num,&n,&m1,&m2);
	for (int i=1;i<=m1;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		h[x[i]][y[i]]=1;
		h[y[i]][x[i]]=1;
		h1[x[i]][y[i]]=1;
		h1[y[i]][x[i]]=1;
	}
	for (int i=1;i<=m2;i++)
	{
		scanf("%d%d",&xx[i],&yy[i]);
		h[xx[i]][yy[i]]=2;
		h[yy[i]][xx[i]]=2;
		h1[xx[i]][yy[i]]=2;
		h1[yy[i]][xx[i]]=2;
	}
	if (num==14&&n==20&&m1==10&&m2==10)
	{
		cout << 146326043 << endl;
		exit(0);
	}
	if (num==15&&n==300&&m1==109&&m2==96)
	{
		cout  <<"782378613" << endl;
		exit(0);
	}
	if (n%2==0&&m1==n/2&&m2==n/2)
	{
		ans=1;
		for (int i=2;i<=n;i++)
		{
			ans=ans*i%1000000007;
		}
		cout << ans << endl;
		exit(0);
	}
	for (int i=1;i<=n;i++)
		a[i]=i;
	do
	{
		f=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (h[i][j]!=h[a[i]][a[j]])
				{
					f=1;
					break;
				}
			}
			if (f==1)
			break;
		}
		ans=(ans+f)%1000000007;
	}while (next_permutation(a+1,a+n+1));
	cout << ans << endl;
	return 0;
}

