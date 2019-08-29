#include<bits/stdc++.h>
using namespace std;
long long ans,MOD=1000000007;
int n,X,MAX;
int a[10010],b[10010],c[10010];
long long deal(int num,int dep,int sum){
	if(dep==0) return 0;
	if(dep==1){
		if((num-sum)%a[1]==0)
			return 1;
		else
			return 0;
	}
	long long m=0;
	
	for(int i=0;i<=c[dep];++i){
		if(i*a[dep]+sum<=num){
			m+=deal(num,dep-1,sum+i*a[dep]);
			m%=MOD;
		}else{
			break;
		}
	}
	return m;
}
long long dfs(int dep,int sum){
	long long m=0;
	if(sum>=X) return deal(sum-X,n,0);
	if(dep==0) return 0;
	for(int i=0;i<=b[dep];++i){
		if(sum+i*a[dep]-X>a[dep-1]) break;
		else{
			m+=dfs(dep-1,sum+i*a[dep]);
			m%=MOD;
		}
	}
	return m%MOD;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>X;
	
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		b[i]=min(b[i],X/a[i]+1);
		c[i]=min(c[i],X/a[i]);
		MAX=max(MAX,a[i]);
	}
	
	
	ans+=dfs(n,0);
	ans%=MOD;
	
	cout<<ans<<endl;
	return 0;
}
