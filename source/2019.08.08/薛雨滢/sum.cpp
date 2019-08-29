#include<bits/stdc++.h>

using namespace std;
const int MAXN=500005;

int n,a[MAXN],dp[MAXN],dpp[MAXN],maxn[MAXN],ans;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=a[i];
		dp[i]=max(dp[i-1]+a[i],dp[i]);
		maxn[i]=max(maxn[i-1],dp[i]);
	}
	
	for(int i=n;i>=1;i--)
	{
		dpp[i]=a[i];
		dpp[i]=max(dpp[i+1]+a[i],dpp[i]);
		ans=max(ans,dpp[i]+maxn[i-1]);
	}
	
	cout<<ans<<endl;
	
	
	return 0;
 } 
