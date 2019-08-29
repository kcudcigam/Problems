#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f;
}
int a[1005];
int b[1005];
int c[1005];
int n,X;
int dp[1005];
const int Mod=1000000007;
inline int dpp(int t,int mx,int who)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++)
		{
			if(a[i]<=mx) continue;
			for(int j=t;j>=a[i];j--)
				{
					if(who==1)for(int k=j-a[i],p=1;k>=0&&p<=b[i];k-=a[i],p++) dp[j]+=dp[k],dp[j]%=Mod;
					if(who==2)for(int k=j-a[i],p=1;k>=0&&p<=c[i];k-=a[i],p++) dp[j]+=dp[k],dp[j]%=Mod;
				}
		}
	return dp[t]%=Mod;
}
signed main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read();
	X=read();
	for(int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
			c[i]=read();
		}
	int ans=0;
	for(int pay=X;pay<X+a[n];pay++)
		{
			int hua=pay-X;
			int p=dpp(pay,hua,1);
			int q=dpp(hua,0,2);
//			cout<<p<<" "<<q<<endl;
			ans+=((p*q)%Mod);
			ans%=Mod;
		}
	cout<<ans<<endl;
	return 0;
}
/*
3 10
1 5 3
3 2 2
5 3 2
*/

