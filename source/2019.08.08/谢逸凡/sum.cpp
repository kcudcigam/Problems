#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
using namespace std;
const int N=1e5+5;
int n;
ll a[N],sum[N],ans;
//int l,r;
ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=ip();rep(i,1,n) a[i]=ip();
	if(n<=3){cout<<0;return 0;}
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	rep(i,1,n) rep(j,i,n) rep(k,j+1,n) rep(m,k,n){
		ans=max(ans,(sum[j]+sum[m])-(sum[i-1]+sum[k-1]));
	}
	cout<<ans;
	return 0;
}

