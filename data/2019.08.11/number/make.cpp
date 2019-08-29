#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define maxi 1000000000000000000ll
using namespace std;
ll x;
int t,na,ans,a[23],su,va[20010],ne[20010][12][10],g[110],ng,dp[20010][22],s[55][55][55];
bool vi[34];
vector<ll> no;
vector<int> n1[20010];
int que(int x,int y){
	int an=0;
	for (int i=0;i<=2;i++)if (y*10+x-i>=0&&vi[y*10-i+x])an|=(1<<i);
	return an;
}
bool check(int x){
	int no=1;
	for (int i=1;i<=na;i++){no=ne[x][a[i]][no];if (!no)return 0;}
	return (no&1);
}
ll R(){return ((1ll*rand()<<45)+(1ll*rand()<<30)+(1ll*rand()<<15)+rand())%1000000000000000000ll+1;}
int que(ll x){
	memset(dp,0,sizeof(dp));
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
	return ans;
}
void make(ll x,int y,int z){
	if (x>0&&x<=maxi)no.pb(x);
	if (x<=maxi){
		if (x!=0||y!=0)make(x*10+y,y,z);
		if (x!=0||z!=0)make(x*10+z,y,z);
	}
}
ll make1(){
	return no[R()%(no.size())];
}
ll make2(){
	ll p=no[R()%(no.size())],q=no[R()%(no.size())];
	while (p+q>maxi)p=no[R()%(no.size())],q=no[R()%(no.size())];
	return p+q;
}
ll make3(){
	ll x=1+R()%maxi;
	while (que(x)!=3)x=1+R()%maxi;
	return x;
}
ll make4(){
	ll x=1+R()%maxi;
	while (que(x)!=4)x=1+R()%maxi;
	return x;
}
int main(){
	freopen("number20.in","w",stdout);
	srand(time(0));
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
	for (int i=0;i<9;i++)
		for (int j=i+1;j<=9;j++)make(0,i,j);
	int t=100;
	cout<<t<<endl;
	while (t--){
		ll np=R()%22;
		if (np>=0)x=make1();
		if (np>=1)x=make2();
		if (np>=2)x=make3();
		if (np>=9)x=make4();
		cout<<x<<endl;
	}
    return 0;
}
//732951930089654456
