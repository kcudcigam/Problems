#include<bits/stdc++.h>
#define gc() getchar()
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) (x<0?-x:x)
using namespace std;
typedef long long ll;
template <typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
const int N=305;
struct node
{
	int l,r;
	bool friend operator <(const node&x,const node&y)
	{
		return x.l<y.l||(x.l==y.l&&x.r<y.r);
	}
}a[N];
struct node1
{
	int l,r;
	bool friend operator <(const node1&x,const node1&y)
	{
		return x.r<y.r||(x.r==y.r&&x.l<y.l);
	}
}b[N];
ll g[10];
ll dp[N][N],dp1[N][N];
bool f[N][N],f1[N][N];
ll gs(int x)
{
	return g[1]*x+g[2]*x*x+g[3]*x*x*x+g[4]*x*x*x*x+g[5]*x*x*x*x*x;
}
int n,m;
void init()
{
	rep(i,1,n)
	{
		int l=a[i].l,r=a[i].r;
		f[i][i]=1;
		rep(j,i+1,n)
		{
			l=max(l,a[j].l);
			r=min(r,a[j].r);
			if(l<=r)
			f[i][j]=1;
			else break;
		}
	}
	rep(i,1,n)
	{
		int l=b[i].l,r=b[i].r;
		f1[i][i]=1;
		rep(j,i+1,n)
		{
			l=max(l,b[j].l);
			r=min(r,b[j].r);
			if(l<=r)
			f1[i][j]=1;
			else break;
		}
	}
}
int ml,mr;
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n),read(m);
	rep(i,1,5)
	read(g[i]);
	rep(i,1,n)read(a[i].l),read(a[i].r),b[i].l=a[i].l,b[i].r=a[i].r;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	init();
	rep(i,1,n)
	{
		ml=max(ml,a[i].l);
		mr=min(mr,a[i].r);
	}
	if(ml<=mr)
	{
		printf("%lld\n",gs(n));
		return 0;
	}
	rep(i,1,n)
	rep(j,1,n)
	{
		if(f[i][j]==1)
		dp[i][j]=gs(j-i+1);
	}
	rep(l,1,n)
	rep(r,l,n)
	rep(i,l,r-1)
	dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
	rep(i,1,n)
	rep(j,1,n)
	{
		if(f1[i][j]==1)
		dp1[i][j]=gs(j-i+1);
	}
	rep(l,1,n)
	rep(r,l,n)
	rep(i,l,r-1)
	dp1[l][r]=max(dp1[l][r],dp1[l][i]+dp1[i+1][r]);
	printf("%lld\n",max(dp[1][n],dp1[1][n]));
	return 0;
}


