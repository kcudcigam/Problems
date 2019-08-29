#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001]={0};
long long d[100001]={0};
long long p[100002]={0};
long long f[100001]={0};
long long ff[100002]={0};
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f[0]=INT_MIN;
	for(int i=1;i<=n;i++){
		d[i]=max(d[i-1]+a[i],(long long)a[i]);
		f[i]=max(f[i-1],d[i]);
	}
	ff[n+1]=INT_MIN;
	for(int i=n;i>=1;i--){
		p[i]=max(p[i+1]+a[i],(long long)a[i]);
		ff[i]=max(ff[i+1],p[i]);
	}
	long long ans=INT_MIN;
	for(int i=1;i<n;i++){
		ans=max(ans,f[i]+ff[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
