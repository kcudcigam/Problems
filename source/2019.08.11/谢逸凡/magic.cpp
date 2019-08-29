#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,k) for(ll i=l;i<=k;i++)

#define mp make_pair 
ll p=998244353;
const int N=1000005;
bool vis[N];
ll t[N],n,m[N];char s[N];
ll ans;
ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
ll qpow(ll y,ll z){
	ll ans=1;
	for(;y;z>>=1) {
		if(z&1) ans=ans*y%p;
		y=y*y%p;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=ip();scanf("%s",s+1);
	cout<<qpow(26-strlen(s)+1,n);
	return 0;
}


