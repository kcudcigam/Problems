#include<bits/stdc++.h>

using namespace std;

#define N 200000
#define ll long long

ll A,B,C,D,n;

inline ll read(){
	ll s = 0,ww = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')ww = -1;ch = getchar();}
	while(isdigit(ch)){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

ll a[N+5],dp[N+5];
ll minn[N+5][20];
ll lg[N+5];

ll getmin(ll l,ll r){
	ll len = r - l + 1,t = lg[len];
	return min(minn[l][t],minn[r - (1 << t) + 1][t]);
}

void pre(){
	ll i,j;
	lg[1] = 0;
	for(i = 2;i <= n;i++)lg[i] = lg[i >> 1] + 1;
	for(i = 1;i <= n;i++)minn[i][0] = a[i];
	for(j = 1;j <= 18;j++){
		for(i = 1;i <= n;i++)minn[i][j] = min(minn[i][j-1],minn[i + (1 << (j - 1))][j-1]);
	}
}

ll f(ll x){
	return A * x * x * x + B * x * x + C * x + D;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	ll i,j;
	n = read();
	A = read();B = read();C = read();D = read();
	for(i = 1;i <= n;i++)a[i] = read();
	pre();
	if(n <= 1000){
		dp[0] = 0;
		for(i = 1;i <= n;i++){
			dp[i] = -1e18;
			for(j = 0;j < i;j++){
				dp[i] = max(dp[i],dp[j] + f(getmin(j+1,i)));
			}
		}
//for(i = 1;i <= n;i++)cout<<dp[i]<<" ";cout<<endl;
		cout<<dp[n]<<endl;
		return 0;
	}
	return 0;
}

