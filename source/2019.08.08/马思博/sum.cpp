#include<bits/stdc++.h>
using namespace std;

long long m[100005],l[100005],r[100005];

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>m[i];
	long long dp[n+5];
	l[1]=m[1];
	for(int i=1;i<=n;i++) dp[i]=m[i];
	for(int i=2;i<=n;i++)
	{ 
	    dp[i]=max(dp[i],dp[i]+dp[i-1]);
	    l[i]=max(l[i-1],dp[i]);
    }
    r[1]=m[n];
	for(int i=1;i<=n;i++) dp[i]=m[n-i+1];
	for(int i=2;i<=n;i++)
	{ 
	    dp[i]=max(dp[i],dp[i]+dp[i-1]);
	    r[i]=max(r[i-1],dp[i]);
    }
    long long ans=l[1]+r[n-1];
//    cout<<ans<<endl;
//    for(int i=1;i<=n;++i) cout<<l[i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=n;++i) cout<<r[n-i+1]<<" ";
//    cout<<endl;
	for(int i=1;i<n;++i)
	{
		long long sum=l[i]+r[n-i];
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
