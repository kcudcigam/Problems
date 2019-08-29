#include<bits/stdc++.h>
#define int long long
using namespace std;
int num,n,m1,m2,m1x[1005],m1y[1005],m2x[1005],m2y[1005];
int h[1005][1005],d[1005][1005],a[1005],ans;
signed main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>m1x[i]>>m1y[i];
		h[m1y[i]][m1x[i]]=h[m1x[i]][m1y[i]]=1;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>m2x[i]>>m2y[i];
		h[m2y[i]][m2x[i]]=h[m2x[i]][m2y[i]]=2;
	}
	if (num<=6)
	{
	for(int i=1;i<=n;i++)
		a[i]=i;
	while(next_permutation(a+1,a+n+1))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=h[a[i]][a[j]];
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if (d[i][j]!=h[i][j]) flag=1;
				if (flag==1) break;
			}
			if (flag==1) break;
		}
		ans+=flag;
		ans%=1000000007;
	}
	cout<<ans<<endl;
	}
	else
	if (num<=10)
	{
		a[0]=1;
		for(int i=1;i<=n;i++)
			a[i]=a[i-1]*i%1000000007;
		int xxx=1;
		for(int i=1;i<=m1+m2;i++)
			xxx=xxx*2%1000000007;
		ans=(a[n]+1000000007-(xxx*a[n-2*m1-2*m2]*a[m1]*a[m2])%1000000007)%1000000007;
		cout<<ans<<endl;
	}
	return 0;
} 
