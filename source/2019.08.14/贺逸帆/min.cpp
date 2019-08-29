#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	T f=1;char c=getchar();x=0;
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n;
ll a[200010];
ll A,B,C,D,ans[200010];
inline ll f(ll x){
	return A*x*x*x+B*x*x+C*x+D;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	fr(n),fr(A),fr(B),fr(C),fr(D);
	
	for(int i=1;i<=n;i++)fr(a[i]);
	
	ans[1]=f(a[1]);
	ll minn=a[1];
	if(n<=9000){
		for(int i=2;i<=n;i++){
			ans[i]=ans[i-1]+f(a[i]);
			minn=a[i];
			for(int j=i-1;j>=1;j--){
				minn=min(minn,a[j]);
				ans[i]=max(ans[i],ans[j-1]+f(minn));
			}
		}
	}else{
		for(int i=2;i<=n;i++){
			if(f(a[i])>=f(min(minn,a[i]))){
				ans[i]=ans[i-1]+f(a[i]);
				minn=a[i];
			}else{
				minn=min(minn,a[i]);
				ans[i]=f(a[i]);
			}
		}
	}
	
	
	cout<<ans[n]<<endl;
	return 0;
}
