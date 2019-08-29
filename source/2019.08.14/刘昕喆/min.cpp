#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C,D;
int a[200002],b[200002];
int f(int x)
{
	return x*x*x*A+x*x*B+x*C+D;
}
signed main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=f(a[i]);
	}
	int Min=LONG_LONG_MAX,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=0)
		{
			if((b[i-1]>=0&&a[i-1]<a[i])||(b[i+1]>=0&&a[i+1]<a[i]))  continue;
			Min=min(Min,a[i]);
		}
		else
		{
			if(Min!=LONG_LONG_MAX)  ans+=f(Min);
			Min=LONG_LONG_MAX;
			ans+=b[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

