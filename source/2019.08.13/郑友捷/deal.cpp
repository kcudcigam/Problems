#include<cstdio>
#include<algorithm>
using namespace std;
int n,val;
int a[1010],b[1010],c[1010];
int f[100010];
int g[110][110][110];
const int mod=1000000007;
inline int calc(int sum,int now,int pos){
	if(now>sum){
		return 0;
	}
	if(g[sum][now][pos]){
		return g[sum][now][pos];
	}
	if(now==sum){
		return 1;
	}
	if(pos==n+1){
		return 0;
	}
	int ans=0;
	for(register int i=0;i<=c[pos];i++){
		ans+=calc(sum,now+a[pos]*i,pos+1);
		ans%=mod;
	}
	g[sum][now][pos]=ans; 
	return ans;
}
inline int dfs(int sum,int now,int minn){
	if(sum-val>=minn){
		return 0;
	}
	if(now==n+1){
		if(sum<val){
			return 0;
		}
		if(f[sum]) {
			return f[sum]%mod; 
		}
		f[sum]=calc(sum-val,0,1);
		f[sum]%=mod;
		return f[sum];
	}
	int ans=0;
	for(register int i=0;i<=b[now];i++){
		if(i!=0){
			int now1=minn;
			minn=min(minn,a[now]);
			ans+=dfs(sum+a[now]*i,now+1,minn);
			ans%=mod;
			minn=now1;
		}
		else {
			ans+=dfs(sum,now+1,minn);
			ans%=mod;
		}
	}
	return ans;
} 
int main(){
	freopen("data.out","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&val);
	for(register int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	printf("%d\n",dfs(0,1,0x7fffffff));
}
