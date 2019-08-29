#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define go(i,u) for(int i=head[u];i;i=nex[i]
using namespace std;
typedef long long ll;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=200005;
int a[N];
int A,B,C,D;
ll calc(int x)
{
	return (ll)A*x*x*x+(ll)B*x*x+(ll)C*x+(ll)D;
}
int n;
ll dp[N];
void solve()
{
	ll ans=0;
	rep(i,1,n)
	if(D>-a[i]*C)
	ans+=D+a[i]*C;
	if(ans==0)
	{
		int mina=0x3f3f3f3f;
		rep(i,1,n)
		mina=min(mina,a[i]);
		ans=D+mina*C;
	}
	printf("%d\n",ans);
}
int f[3005][3005];
void ST_prework()
{
	rep(i,1,n)
	f[i][0]=a[i];
	int t=log(n)/log(2)+1;
	for(int j=1;j<=t;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
}
int query(int l,int r)
{
	int k=log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n),read(A),read(B),read(C),read(D);
	rep(i,1,n)
	read(a[i]);
	if(A==0&&B==0&&C<=0)
	{
		solve();
		return 0;
	}
	ST_prework();
	dp[0]=0;
	rep(i,0,n)
	rep(j,i+1,n)
	dp[j]=max(dp[j],dp[i]+calc(query(i+1,j)));
	printf("%lld\n",dp[n]);
	return 0;
}



