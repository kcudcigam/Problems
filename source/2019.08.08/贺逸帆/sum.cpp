#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=1e5+10;
ll f1[N],f2[N];
int a[N];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	fr(n);
	
	for(int i=1;i<=n;i++)fr(a[i]);
	
	for(int i=1;i<=n;i++)
		if(f1[i-1]>=0)f1[i]=f1[i-1]+a[i];
		else f1[i]=a[i];
	
	for(int i=n;i>=1;i--)
		if(f2[i+1]>=0)f2[i]=f2[i+1]+a[i];
		else f2[i]=a[i];
	
	ll ans=-LONG_LONG_MAX;
	for(int i=2;i<n;i++){
		ans=max(ans,f1[i-1]+f2[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}


