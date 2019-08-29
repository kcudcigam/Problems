#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,maxn=1e6;
int n,m,X;
long long ans;
struct node{
	int w,a,b;
}z[150];
int num1[maxn],num2[maxn]={1};
int dp[maxn];
void dfs1(int cur,int sum,int minn){
	if(sum>=X&&sum-X<minn)
		num1[sum-X]=(num1[sum-X]+1)%mod;
//		cout<<sum-X<<endl;
	if(cur==n+1)
		return;
	int i,j;
	dfs1(cur+1,sum,minn);
	for(i=1;i<=z[cur].a;i++)
		dfs1(cur+1,sum+i*z[cur].w,min(minn,z[i].w));
}
void dfs2(int cur){
	if(cur==n+1)
		return;
	int i,j,k;
	for(k=1;k<=z[cur].b;k++)
		for(i=m;i>=z[cur].w*k;i--)
			if(num2[i-z[cur].w*k])
				dp[i]=(dp[i]+num2[i-z[cur].w*k])%mod;
	for(i=1;i<=m;i++)
		num2[i]=(num2[i]+dp[i])%mod;
	dfs2(cur+1);
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&X);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&z[i].w,&z[i].a,&z[i].b);
		m+=z[i].w*z[i].b;
	}
	dfs1(1,0,100005);
	dfs2(1);
	for(i=0;i<=m;i++)
		ans=(ans+num1[i]*num2[i]%mod)%mod;
/*	for(i=1;i<=m;i++)
		cout<<i<<"   "<<num1[i]<<endl;*/
	printf("%lld",ans);
	return 0;
}
