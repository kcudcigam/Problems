#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,m;
long long f[310][310];
inline long long dfs(int x,int y){
	if(f[x][y]){
		return f[x][y];
	}
	if(x==1&&y==1){
		f[x][y]=1;
		return 1;
	}
	long long ans=0;
	for(register int i=1;i<x;i++){
		ans=(ans+(dfs(i,y)*dfs(x-i,y)%mod))%mod;
	}
	for(register int i=1;i<y;i++){
		ans=(ans+(dfs(x,i)*dfs(x,y-i)%mod))%mod;
	}
	f[x][y]=ans;
	return f[x][y];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout); 
	scanf("%d%d",&n,&m);
	dfs(n,m);
	printf("%lld\n",f[n][m]);
	printf("\n");
}
