#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
#define N 100100
#define ll long long
ll a[N],l[N],r[N],dp[N];//dp[i]表示以i结尾的最大连续子段和,l[i]表示1~i的最大连续子段和,r[i]表示i~n的最大连续子段和 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n); 
	for(int i=1;i<=n;i++) read(a[i]);
	dp[0]=-1e9-1;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1]+a[i],a[i]);
	}
	for(int i=1;i<=n;i++) l[i]=max(l[i-1],dp[i]);
	dp[n+1]=-1e9-1;
	for(int i=n;i>0;i--){
		dp[i]=max(dp[i+1]+a[i],a[i]);
	}
	for(int i=n;i>0;i--) r[i]=max(r[i+1],dp[i]);
	ll ans=0;
	r[n+1]=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,l[i]+r[i+1]);
	}
	printf("%lld",ans);
	return 0;
}
