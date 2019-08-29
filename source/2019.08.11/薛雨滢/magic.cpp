#include<bits/stdc++.h>

using namespace std;
const int mod=998244353;

int n;
int dp[5][5];
char s[1000005];

int expow(int x,int t)
{
	int ans=1;x%=mod;
	while(t)
	{
		if(t%2ll) ans=(ans*x)%mod;
		x=(x*x)%mod;
		t>>=1ll;
	}
	return ans%mod;
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);

	cin>>n;
	int ans=expow(26,n);
	scanf("%s",s);
	int len=strlen(s);
	dp[2][1]=51;
	dp[3][1]=1951;
	dp[3][2]=1326;
	dp[3][3]=1;
	dp[4][1]=66351;
	dp[4][2]=2601;
	dp[4][4]=1;
	if(len==0) {cout<<ans-1<<endl;return 0;}
	if(n==len) {cout<<ans-1<<endl;return 0;}
	if(n-len==1)
	{
		cout<<25<<endl;
		return 0;
	}
	if(n<=4&&len<=4) cout<<(ans-dp[n][len]+mod)%mod<<endl;
	return 0;
	fclose(0);
 } 
