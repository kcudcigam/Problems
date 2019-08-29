#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &t)
{
	t=0; int f=1,c;
	while(c=getchar(),(c<'0'||c>'9')&&c!='-');
	if(c!='-') t=c-'0';
	else f=-1;
	while(c=getchar(),'0'<=c&&c<='9') t=t*10+c-'0';
	t=t*f;
}
template<typename T,typename... Args> inline void read(T &t,Args&... args) { read(t); read(args...); }
const int maxn=255;
const int maxm=10000005;
LL x[6],f[maxn],maxv[maxn][maxn],dp[maxn],res;
int n,m,cl;
struct Data { int l,r; } a[maxn];
inline bool operator<(const Data &a,const Data &b) { return a.l<b.l||(a.l==b.l&&a.r<b.r); }
void Proc()
{
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i;k++)
				maxv[i][j]=max(maxv[i][j],maxv[i-k][j-1]+f[k]);
}
void DP()
{
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		int L=a[i].l,R=a[i].r;
		for(int j=i;j>=1&&L<=R;j--,R=min(R,a[j].r),L=max(L,a[j].l),++cl)
			dp[i]=max(dp[i],dp[j-1]+maxv[i-j+1][min(i-j+1,R-L+1)]);
	}
	res=max(res,dp[n]);
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	srand(260817);
	read(n,m,x[1],x[2],x[3],x[4],x[5]);
	for(int i=1;i<=n;i++) f[i]=((((x[5]*i+x[4])*i+x[3])*i+x[2])*i+x[1])*i;
	bool flg1=1;
	for(int i=1;i<=n;i++)
	{
		read(a[i].l,a[i].r);
		if(a[i].l!=1||a[i].r!=m) flg1=0;
	}
	if(flg1) { printf("%lld\n",f[n]); return 0; }
	Proc();
	DP();
	while(cl+n*n<=20000000)
	{
		random_shuffle(a+1,a+1+n);
		DP();
	}
	printf("%lld\n",res);
	return 0;
}
