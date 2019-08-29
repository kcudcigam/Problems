#include<bits/stdc++.h>
using namespace std;

long long a[50010];
int n;

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	a[n+1]=-1e13-1;
	int f=0,r=1;
	long long ans1=-1e13-1,ans2=-1e13-1;
	for (int i=1;i<=n+1;++i){
		if (a[i]<=a[f]&&i>f+1){
			if (ans1<a[i-1]-a[f]){
				ans2=ans1;
				ans1=a[i-1]-a[f];
			}
			else ans2=max(ans2,a[i-1]-a[f]);
			f=i;
			continue;
		}
		if (a[i]<=a[f]){
		if (ans1<=a[i]-a[f]){
				ans2=ans1;
				ans1=a[i]-a[f];
			}
			else ans2=max(ans2,a[i]-a[f]);
			f=i;
			continue;
		}
	}
	long long ans;
	if (ans2==-1e13-1)	ans=ans1;
		else ans=ans1+ans2;
	printf("%lld",ans);
	return 0;
}


