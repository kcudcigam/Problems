#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int flag,n,m1,m2;
int a[1010][1010];
long long calc(long long x){
	long long ans=1;
	for(long long i=x;i>=2;i--)
		ans=(ans*i)%mod;
	return ans;
}
long long two(int x){
	if(x==0)return 1;
	else if(x==1)return 2;
	long long ans=two(x/2);
	if(x%2==0)return ans*ans%mod;
	else return ans*2%mod*ans%mod;
} 
//30+20=50
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d%d%d%d",&flag,&n,&m1,&m2);
	if(flag<=2)printf("0\n");
	else if(flag<=6){
		for(int i=1;i<=m1;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=1;
		}
		for(int i=1;i<=m2;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=2;
		}
		int p[1010];
		for(int i=1;i<=n;++i)p[i]=i;
		long long ans=0;
		while(next_permutation(p+1,p+n+1)){
			for(int i=1;i<n;++i)
				for(int j=i+1;j<=n;++j)
					if(a[i][j]!=a[p[i]][p[j]]){
						ans=(ans+1)%mod;
						goto end;
					}
			end:continue;
		}
		printf("%lld\n",ans);
	}
	else if(flag<=10){
		long long cans=two(m1+m2)*calc(m1)%mod
				*calc(m2)%mod
				*calc(n-2*(m1+m2))%mod;
		printf("%lld\n",(calc(n)-cans+mod)%mod);
	}
	return 0;
} 
