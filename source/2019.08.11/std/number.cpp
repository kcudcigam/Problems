#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll x;
int t,na,ans,a[23],su,va[20010],g[110],ng,s[55][55][55],dp[20010][22];
bool vi[20010][34];
vector<int> n1[20010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=0;i<=8;i++)
		for (int j=i+1;j<=9;j++)g[++ng]=i*10+j;
	memset(vi,0,sizeof(vi));
	for (int i=0;i<=ng;i++){
		for (int j=i;j<=ng;j++){
			for (int k=j;k<=ng;k++){
				va[++su]=3;
				if (k==0)va[su]--;if (j==0)va[su]--;if (i==0)va[su]--;
				vi[su][g[i]/10+g[j]/10+g[k]/10]=1;vi[su][g[i]/10+g[j]/10+g[k]%10]=1;
				vi[su][g[i]/10+g[j]%10+g[k]/10]=1;vi[su][g[i]/10+g[j]%10+g[k]%10]=1;
				vi[su][g[i]%10+g[j]/10+g[k]/10]=1;vi[su][g[i]%10+g[j]/10+g[k]%10]=1;
				vi[su][g[i]%10+g[j]%10+g[k]/10]=1;vi[su][g[i]%10+g[j]%10+g[k]%10]=1;
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
				for (int la=0;la<=2;la++)
					if (dp[j][i+1]&(1<<la))
						for (int no=0;no<=2;no++)
							if (la*10+a[i]-no>=0&&vi[j][la*10+a[i]-no])dp[j][i]|=(1<<no);
				for (auto k:n1[j])dp[j][i]|=dp[k][i];
			}
		}
		for (int i=1;i<=su;i++)if (dp[i][1]&1){ans=min(ans,va[i]);break;}
		cout<<ans<<endl;
	}
    return 0;
}
