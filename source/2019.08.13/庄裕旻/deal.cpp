#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
const int maxn=1005;
const int maxv=10005;
int n,X,a[maxn],b[maxn],c[maxn];
LL f[2][maxv*2],g[2][maxv*2];
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	f[0][0]=g[0][0]=1;
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	reverse(a+1,a+1+n); reverse(b+1,b+1+n); reverse(c+1,c+1+n);
	for(int i=1;i<=n;i++)
	{
		memcpy(f[i&1],f[(i-1)&1],maxv*2*sizeof(LL));
		memcpy(g[i&1],g[(i-1)&1],maxv*2*sizeof(LL));
		for(int st=0;st<a[i];st++)
		{
			LL tot=f[(i-1)&1][st]; int head=st;
			for(int j=st+a[i];j<=20000&&j<X+a[i];j+=a[i])
			{
				if((j-head)/a[i]>b[i]) { tot-=f[(i-1)&1][head]; tot<0?tot+=mod:0; head+=a[i]; }
				f[i&1][j]+=tot; f[i&1][j]<mod?0:f[i&1][j]-=mod;
				tot+=f[(i-1)&1][j]; tot<mod?0:tot-=mod;
			}
		}
		for(int st=0;st<a[i];st++)
		{
			LL tot=g[(i-1)&1][st]; int head=st;
			for(int j=st+a[i];j<=20000;j+=a[i])
			{
				if((j-head)/a[i]>c[i]) { tot-=g[(i-1)&1][head]; tot<0?tot+=mod:0; head++; }
				g[i&1][j]+=tot; g[i&1][j]<mod?0:g[i&1][j]-=mod;
				tot+=g[(i-1)&1][j]; tot<mod?0:tot-=mod;
			}
		}
	}
	LL res=0;
	for(int i=X;i<=20000;i++) res=(res+f[n&1][i]*g[n&1][i-X])%mod;
	printf("%lld\n",res);
	return 0;
}
