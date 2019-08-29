#include<bits/stdc++.h>

using namespace std;

#define N 100000
#define mod 1000000007
#define ll long long

inline ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

ll n,m,q;

vector<ll>v[N+5]; // case 5
vector<ll>s[N+5]; // case 5

ll w[N+5],p[N+5];

ll x[25],y[25],cnt[25],L[25],R[25],mxn[25][5],lg[25]; // case 1

ll check(ll x){
	return ((x % mod) + mod) % mod;
}

void inc(ll &x,ll dx){
	x = (x + dx) % mod;
}

bool cmp(ll x,ll y){
	return w[x] < w[y];
}

void pre(){
	ll i,j;
	lg[1] = 0;
	for(i = 1;i <= n;i++)lg[i] = lg[i >> 1] + 1;
	for(i = 1;i <= n;i++)mxn[i][0] = cnt[i];
	for(j = 1;j <= 4;j++){
		for(i = 1;i <= n;i++)mxn[i][j] = max(mxn[i][j-1],mxn[i + (1ll << (j - 1))][j-1]);
	}
}

ll query(ll l,ll r){
	ll len = r - l + 1,t = lg[len];
	return max(mxn[l][t],mxn[r+1-(1ll << t)][t]);
}

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	ll i,j;
	n = read();m = read();q = read();
	if(q == n){
		for(i = 1;i <= m;i++){
			ll x = read();
			w[i] = read(),p[i] = read();
			if(p[i] == 0)continue;
			v[x].push_back(i);
		}
		for(i = 1;i <= n;i++)if(v[i].size())sort(v[i].begin(),v[i].end(),cmp);
/*for(i = 1;i <= n;i++){
	for(j = 0;j < v[i].size();j++)cout<<v[i][j]<<" ";cout<<endl;
}*/
		for(i = 1;i <= n;i++){
			if(v[i].size() == 0)continue;
			s[i].push_back(check(1 - p[v[i][0]]));
			for(j = 1;j < v[i].size();j++)s[i].push_back(s[i][j-1] * check(1 - p[v[i][j]]) % mod);
		}
/*for(i = 1;i <= n;i++){
	for(j = 0;j < v[i].size();j++)cout<<s[i][j]<<" ";cout<<endl;
}*/
		ll ans = 0;
		for(i = 1;i <= n;i++){
			if(v[i].size() == 0)continue;
			ll cur = 0;
			inc(cur,p[v[i][0]] * w[v[i][0]] % mod);
			for(j = 1;j < v[i].size();j++)inc(cur,s[i][j-1] * w[v[i][j]] % mod * p[v[i][j]] % mod);
//cout<<cur<<endl;
			inc(ans,cur);
		}
		cout << ans << endl;
		return 0;
	}
	
	if(n <= 20){
		ll mask,j,k,ans = 0;
		for(i = 1;i <= n;i++)x[i] = read(),y[i] = read(),p[i] = read();
		for(i = 1;i <= q;i++)L[i] = read(),R[i] = read();
		for(mask = 0;mask < (1ll << m);mask++){
			ll pr = 1;
			for(j = 1;j <= n;j++)cnt[j] = 2147483647;
			for(j = 1;j <= m;j++){
				bool id = (bool)((1 << (j - 1)) & mask);
				if(id)pr = pr * p[j] % mod;
				else pr = pr * check(1 - p[j]) % mod;
				if(id)cnt[x[j]] = min(cnt[x[j]],y[j]);
			}
			for(j = 1;j <= n;j++)if(cnt[j] == 2147483647)cnt[j] = 0;
//			pre();
			for(j = 1;j <= q;j++){
				ll t = 0;
//				ll t = query(L[j],R[j]);
				for(k = L[j];k <= R[j];k++)t = max(t,cnt[k]);
				inc(ans,t * pr % mod);
			}	
		}
		cout << ans << endl;
		return 0;
	}
	
	return 0;
}

