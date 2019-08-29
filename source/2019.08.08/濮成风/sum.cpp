#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=1E5+5;
const ll inf=1E9; 
int n;
ll a[maxn],f[maxn][2],g[maxn][2],ans;
void sp()
{
	ll max1=-inf,max2=-inf;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>max1)
			max2=max1,max1=a[i];
		else if(a[i]>max2)
			max2=a[i];
	}
	cout<<max1+max2<<endl;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]>=0)
			++tot;
	}
	if(tot<=1)
	{
		sp();
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=max(a[i],f[i-1][1]+a[i]);
	}
	for(int i=n;i>=1;--i)
	{
		g[i][0]=max(g[i+1][0],g[i+1][1]);
		g[i][1]=max(a[i],g[i+1][1]+a[i]);
	}
	for(int i=1;i<=n-1;++i)
		ans=max(ans,max(f[i][0],f[i][1])+max(g[i+1][0],g[i+1][1]));
	cout<<ans<<endl;
	return 0;
}

