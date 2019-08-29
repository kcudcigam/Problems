#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,f[1005][1005],a[100005],Ans,tot[100005];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	memset(f,-0x3f3f3f3f,sizeof(f));
	for (int i = 1; i <= n; ++ i){
		scanf("%d",&a[i]);
		f[i][i] = a[i];
		tot[i] = tot[i-1]+a[i];
	}
	for (int k = 1; k < n; ++ k)
		for (int i = 1; i <= n-k; ++ i){
			f[i][i+k] = max(f[i][i+k-1],max(f[i+1][i+k],max(tot[i+k]-tot[i-1],tot[i+k]-tot[i-1])));
		}
	for (int i = 1; i < n; ++ i)
		Ans = max(Ans,f[1][i]+f[i+1][n]);
	printf("%d",Ans);
}
