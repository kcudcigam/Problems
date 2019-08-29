#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[400][400];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main()
{
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    int a,b;
    read(a);
    read(b);
    dp[1][1]=1;
    for(int i=1;i<=a;i++)
    {
    	for(int j=1;j<=b;j++)
    	{
    		for(int k=1;k<=i;k++)
    		{
    			dp[i][j]+=(dp[k][j]*dp[i-k][j])%mod;			
			}
			for(int k=1;k<=j;k++)
			{
				dp[i][j]+=(dp[i][k]*dp[i][j-k])%mod;
			}
			dp[i][j]%=mod;
		}
	}
	printf("%lld",(dp[a][b])%mod);
}
