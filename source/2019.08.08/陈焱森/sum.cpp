#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

typedef long long ll;

ll a[1005],sum[1005],s[1005][1005],f[1005][1005];
ll ans=LLONG_MIN;

int main(void) {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;++i) {
		f[i][i]=a[i];
		for(int j=i;j<=n;++j)
			s[i][j]=sum[j]-sum[i-1];
	}
	for(int len=2;len<=n;++len)
		for(int i=1;i<=n-len+1;++i) {
			f[i][i+len-1]=max(max(f[i][i+len-2],f[i+1][i+len-1]),s[i][i+len-1]);
		}
	for(int k=1;k<n;++k) {
		ans=max(ans,f[1][k]+f[k+1][n]);
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
}
