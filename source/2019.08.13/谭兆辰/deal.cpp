#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,x;
int a[1010],b[1010],c[1010];
int amax=0,sum;
int dp[1010][20020],dep[1010][20020],f[20020];
const int mod=1e9+7;
#include <algorithm>
#define R register
int ans=0;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout); 
	scanf("%d%d",&n,&x);
	for(int i=n;i>0;i--){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		amax=max(amax,a[i]);
	}
	sum=a[1]*b[1];
	for(R int i=1;i<=amax+x&&i<=sum;i++){
		if(i%a[1]==0) dp[1][i]=1;
		else dp[1][i]=0;
	}
	for(int i=1;i<=n;i++) dp[i][0]=1;
	for(R int i=2;i<=n;i++){
		sum=min(x+amax,sum+a[i]*b[i]);
		for(R int j=0;j<a[i];j++) f[j]=0;
		for(R int j=0;j<=sum&&j<=amax+x;j++){
			f[j%a[i]]+=dp[i-1][j],f[j%a[i]]%=mod;
			if(j-a[i]*b[i]>0) f[j%a[i]]-=dp[i-1][j-a[i]*b[i]];
			if(f[j%a[i]]<0) f[j%a[i]]=(f[j%a[i]]+mod)%mod;
			dp[i][j]=f[j%a[i]];
		}
	}
//	cout<<a[1]<<" "<<b[1]<<"\n";
	reverse(a+1,a+1+n),reverse(b+1,b+1+n),reverse(c+1,c+1+n);
	sum=a[1]*c[1];
//	cout<<a[1]<<" "<<b[1]<<"\n";
	for(R int i=1;i<=amax+x&&i<=sum;i++){
		if(i%a[1]==0) dep[1][i]=1;
		else dep[1][i]=0;
//		cout<<dep[1][i]<<" ";
	}
	for(int i=1;i<=n;i++) dep[i][0]=1;
	for(R int i=2;i<=n;i++){
		sum=min(x+amax,sum+a[i]*c[i]);
//		cout<<sum<<" ";
		for(R int j=0;j<a[i];j++) f[j]=0;
		for(R int j=0;j<=sum&&j<=amax+x;j++){
			f[j%a[i]]+=dep[i-1][j],f[j%a[i]]%=mod;
			if(j-a[i]*c[i]>0) f[j%a[i]]-=dep[i-1][j-a[i]*c[i]];
			if(f[j%a[i]]<0) f[j%a[i]]=(f[j%a[i]]+mod)%mod;
			dep[i][j]=f[j%a[i]];
			cout<<dep[i][j]<<" ";
		}
		cout<<"\n";
	}
//	for(int i=1;i<=15;i++) cout<<dep[n][i]<<" ";
	for(R int i=x;i<=x+amax;i++){
		R int k=x-i;
		R int p=lower_bound(a+1,a+1+n,k)-a;
		if(a[p]==k) p++;
		ans=(ans+1ll*dp[n-p][i]*dep[n][i]%mod)%mod;
	}
	cout<<ans;
	return 0;
}
