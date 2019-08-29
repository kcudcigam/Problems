#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
LL f[305][305];
LL dp(int n,int m)
{
	if(n>m) swap(n,m);
	if(f[n][m]!=-1) return f[n][m];
	LL &res=f[n][m];
	res=0;
	for(int i=1;i<n;i++) res=(res+dp(i,m)*dp(n-i,m))%mod;
	for(int i=1;i<m;i++) res=(res+dp(n,i)*dp(n,m-i))%mod;
	return res;
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	memset(f,-1,sizeof(f)); f[1][1]=1;
	int n,m; scanf("%d%d",&n,&m);
	printf("%lld\n",dp(n,m));
	return 0;
}
