#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
ll n,a[N],s[N],und[N],under2[N],cnt=0,cnt2=0,ans=0,cntup;
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(ll i=1;i<=n;i++) read(a[i]),cntup+=(a[i]<0?0:1);
	if(cntup<2){
		ll maxn=-1000000007,sec=-1000000007;
		for(ll i=1;i<=n;i++)
			if(a[i]>maxn) sec=maxn,maxn=a[i];
			else if(a[i]>sec) sec=a[i];
		cout<<maxn+sec<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		if(s[i]<0&&a[i+1]>=0) und[++cnt]=i;
		if(s[n]-s[i-1]<0&&a[i-1]>=0) under2[cnt2++]=i;
	}
	under2[cnt2]=n+1;
//	for(ll i=0;i<=cnt;i++) cout<<und[i]<<endl;
//	cout<<"-------"<<endl;
//	for(ll i=0;i<=cnt2;i++) cout<<under2[i]<<endl; 
	ans=0;
	for(ll i=0;i<=cnt;i++){
		if(und[i]>n-2) break;
		for(ll j=cnt2;j>=0&&under2[j]-und[i]>3;j++){
//			cout<<"-------------"<<endl;
			ll sum=0x3f3f3f3f,st=und[i]+2,minx=0x3f3f3f3f;
			for(ll k=und[i]+2;k<under2[j]-1;k++){
				if(s[k]-s[st-1]>0) st=k+1;
				sum=min(sum,s[k]-s[st-1]);
				minx=min(minx,a[k]);
			}
			if(minx>0) ans=max(ans,s[under2[j]-1]-s[und[i]]-minx);
			else ans=max(ans,s[under2[j]-1]-s[und[i]]-sum);
//			cout<<und[i]<<' '<<under2[j]<<' '<<sum<<' '<<minx<<' '<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
