#include <bits/stdc++.h>
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
typedef long long ll;
const int N=1010;
const int M=5010;
const ll MOD=1000000007ll;
ll dp1[N][M],dp2[N][M];
struct node{
	int w,a,b;
}a[N];
int w[N];
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int n,s;read(n),read(s);
//	cerr << sizeof(int[1010][5010]);
	int t=0;
	for (int i=1;i<=n;i++){
		read(a[i].w),read(a[i].a),read(a[i].b);
		w[i]=a[i].w;
	}
	t=(s+w[n])*2;
	reverse(a+1,a+n+1);
	dp1[0][0]=dp2[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=t;j++){
			for (int k=0;k*a[i].w<=j&&k<=a[i].a;k++)
				dp1[i][j]=(dp1[i][j]+dp1[i-1][j-k*a[i].w])%MOD;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=t;j++){
			for (int k=0;k*a[i].w<=j&&k<=a[i].b;k++)
				dp2[i][j]=(dp2[i][j]+dp2[i-1][j-k*a[i].w])%MOD;
		}
	}
	ll ans=0;
	for (int i=s;i<=t;i++){
		int p=upper_bound(w+1,w+n+1,i-s)-w;
		if (p>n) break;
		else p=n-p+1;
//		cerr << dp1[p][i] << " " << dp2[n][i-s] << endl;
		ans=(ans+dp1[p][i]*dp2[n][i-s]%MOD)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3 10
1 5 3
3 2 2
5 3 2
*/
