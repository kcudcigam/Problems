#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll x;
int t,na,ans,a[23],su,va[20010],ne[20010][12][10],g[110],ng,s[55][55][55],dp[20010][22];
bool vi[34];
vector<int> n1[20010];
int que(int x,int y){
	int an=0;
	for (int i=0;i<=2;i++)if (y*10+x-i>=0&&vi[y*10-i+x])an|=(1<<i);
	return an;
}
int main(){
	freopen("number20.in","r",stdin);
	freopen("number20.out","w",stdout);
	for (int i=0;i<=8;i++)
		for (int j=i+1;j<=9;j++)g[++ng]=i*10+j;
	for (int i=0;i<=ng;i++){
		for (int j=i;j<=ng;j++){
			for (int k=j;k<=ng;k++){
				va[++su]=3;
				if (k==0)va[su]--;if (j==0)va[su]--;if (i==0)va[su]--;
				memset(vi,0,sizeof(vi));
				vi[g[i]/10+g[j]/10+g[k]/10]=1;vi[g[i]/10+g[j]/10+g[k]%10]=1;vi[g[i]/10+g[j]%10+g[k]/10]=1;vi[g[i]/10+g[j]%10+g[k]%10]=1;
				vi[g[i]%10+g[j]/10+g[k]/10]=1;vi[g[i]%10+g[j]/10+g[k]%10]=1;vi[g[i]%10+g[j]%10+g[k]/10]=1;vi[g[i]%10+g[j]%10+g[k]%10]=1;
				for (int n1=0;n1<8;n1++)
					for (int n2=0;n2<=9;n2++)
						for (int p=0;p<=2;p++)
							if (n1&(1<<p))ne[su][n1][n2]|=que(n2,p);
				s[i][j][k]=s[j][i][k]=s[j][k][i]=s[k][j][i]=s[i][k][j]=s[k][i][j]=su;
				if (s[i][j][0]!=su)n1[su].pb(s[i][j][0]);
				if (s[i][0][k]!=su)n1[su].pb(s[i][0][k]);
				if (s[0][j][k]!=su)n1[su].pb(s[0][j][k]);
				if (s[i][0][0]!=su)n1[su].pb(s[i][0][0]);
				if (s[0][0][k]!=su)n1[su].pb(s[0][0][k]);
				if (s[0][j][0]!=su)n1[su].pb(s[0][j][0]);
				if (s[0][0][0]!=su)n1[su].pb(s[0][0][0]);
			}
		}
	}
	cin>>t;
	while (t--){
		memset(dp,0,sizeof(dp));
		cin>>x;
		na=0,ans=4;
		while (x){a[++na]=x%10;x/=10;}
		for (int i=1;i<=su;i++)dp[i][na+1]=1;
		for (int i=na;i>=1;i--){
			for (int j=1;j<=su;j++){
				dp[j][i]=ne[j][dp[j][i+1]][a[i]];
				for (auto k:n1[j])dp[j][i]|=dp[k][i];
			}
		}
		for (int i=1;i<=su;i++)if (dp[i][1]&1) ans=min(ans,va[i]);
		cout<<ans<<endl;
	}
    return 0;
}
