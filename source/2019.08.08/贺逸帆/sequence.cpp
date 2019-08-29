#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500010;
ll tree[N],sum[N];
int n,m;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	fr(n),fr(m);
	
	int l,r;
	ll s,e,delta;
	while(m--){
		fr(l),fr(r),fr(s),fr(e);
		if(e!=s){
			delta=(e-s)/(r-l);
			tree[l]+=s;
			tree[l+1]+=delta-s;
			tree[r+1]+=-delta-e;
		}else{
			tree[l]+=s;
			tree[l+1]+=-s;
			tree[r+1]+=-s;
		}
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+tree[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		ans^=sum[i];
	}
	cout<<ans<<endl;
	return 0;
}


