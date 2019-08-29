#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define N 10000
#define mod 1000000007

ll f[2*N+5],g[N+5],d[2*N+5];
ll a[N+5],b[N+5],c[N+5];
ll n,x,maxa,maxw,sum;

inline ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

void inc(ll &sum,ll x){
	sum = (sum + x) % mod;
}

void dec(ll &sum,ll x){
	sum = (((sum - x) % mod) + mod) % mod;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	ll i,j,k,t,maxa;
	n = read();x = read();
	for(i = 1;i <= n;i++)a[i] = read(),b[i] = read(),c[i] = read();
	maxa = a[n];
	maxw = x + maxa - 1;
//cout<<"maxa="<<maxa<<" maxw="<<maxw<<endl;
	g[0] = 1;
	for(i = 1;i < n;i++){
		for(j = 0;j < a[i];j++){
			sum = 0;
			for(t = j;t < maxa;t += a[i]){
				d[t] = sum;
				inc(sum,g[t]);
				if(t - a[i] * c[i] >= 0)dec(sum,g[t - a[i] * c[i]]);
			}
		}
//for(j = 0;j < maxa;j++)cout<<d[j]<<" ";cout<<endl;
		for(j = 1;j < maxa;j++)inc(g[j],d[j]);
	}
//for(i = 0;i < maxa;i++)cout<<g[i]<<" ";cout<<endl;
	ll ans = 0;
	f[0] = 1;
	for(i = n;i >= 1;i--){
//cout<<"i="<<i<<" a="<<a[i]<<" b="<<b[i]<<endl;
		for(j = 0;j < a[i];j++){
			sum = 0;
			for(t = j;t <= maxw;t += a[i]){
				d[t] = sum;
				inc(sum,f[t]);
				if(t - a[i] * b[i] >= 0)dec(sum,f[t - a[i] * b[i]]);
			}
		}
		for(j = 1;j <= maxw;j++)inc(f[j],d[j]);
//for(j = 0;j <= maxw;j++)cout<<f[j]<<" ";cout<<endl;
		for(j = x + a[i] - 1;j >= x + a[i-1];j--)inc(ans,f[j] * g[j-x] % mod);
	}
	cout<<ans<<endl;	
	return 0;
}

