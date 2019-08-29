#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
int a[100010],sum[100010];
signed main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k;l<=n;l++){
					ans=max(ans,sum[j]-sum[i-1]+sum[l]-sum[k-1]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3
*/

