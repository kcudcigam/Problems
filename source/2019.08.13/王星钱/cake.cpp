#include <bits/stdc++.h>
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
typedef long long ll;
const int N=310;
const ll MOD=1000000007ll;
ll f[N][N];
ll dp(int i,int j){
	if (f[i][j])return f[i][j];
	ll& d=f[i][j]; 
	for (int k=1;k<i;k++)
		d=(d+dp(k,j)*dp(i-k,j)%MOD)%MOD;
	for (int k=1;k<j;k++)
		d=(d+dp(i,k)*dp(i,j-k)%MOD)%MOD;
	return d;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	f[1][1]=1;
	int n,m;read(n),read(m);
	printf("%lld\n",dp(n,m));
	return 0;
}
