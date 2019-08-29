#include<bits/stdc++.h>
using namespace std;

int a[5005],b[5005],c[5005];
int f[5005][5005],t[5005][5005];

int main()
{  
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (int i=n;i>=1;i--) c[i]=c[i+1]+a[i];
	for (int i=n;i>1;i--)
	{
		t[i][i]=max(a[i],0);
		for (int j=i-1;j>=1;j--)
		{
			t[i][j]=max(t[i][j+1],c[j]-c[i+1]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		f[i][i]=max(a[i],0);
		if (i==n) break;
		for (int j=i+1;j<=n;j++)
		{	
			f[i][j]=max(max(b[j]-b[i-1],t[j][i]),f[i][j-1]);
		}
	}
	int ans=0;
	for (int i=1;i<n;i++)
	{
		ans=max(ans,f[1][i]+f[i+1][n]);
	}
	cout<<ans<<endl;
	return 0;
} 
