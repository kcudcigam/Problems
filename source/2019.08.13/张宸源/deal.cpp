#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define Rep(i,x,y) for(int i=x;i>=y;--i)
#define min(x,y) (x<y?x:y)
using namespace std;
const int mod=1000000007;
typedef long long ll;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
int dpa[1005][20005],dpb[1005][10005],suma[1005][10005],sumb[1005][10005];
int n,x;
int a[1005],b[1005],c[1005];
int maxa[1005],maxb[1005];
ll ans;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n),read(x);
	rep(i,1,n)
	read(a[n-i+1]),read(b[n-i+1]),read(c[n-i+1]);
	rep(i,1,n)
	{
		maxa[i]=min(min(maxa[i-1],2*x)+a[i]*b[i],2*x);
		maxb[i]=min(min(maxb[i-1],x)+a[i]*c[i],x);
	}
	dpa[0][0]=dpb[0][0]=1;
	rep(i,1,n)
	rep(j,0,maxa[i-1])
	rep(k,0,b[i])
	if(j+k*a[i]<=2*x)
	(dpa[i][j+k*a[i]]+=dpa[i-1][j])%=mod;
	else break;
	rep(i,1,n)
	rep(j,0,maxb[i-1])
	rep(k,0,c[i])
	if(j+k*a[i]<=x)
	(dpb[i][j+k*a[i]]+=dpb[i-1][j])%=mod;
	else break;
	dpa[0][0]=dpb[0][0]=0;
	rep(i,0,2*x)
	Rep(j,n,1)
	dpa[j][i]-=dpa[j-1][i];
	rep(i,0,x)
	rep(j,n,1)
	dpb[j][i]-=dpb[j-1][i];
	rep(i,0,x)
	rep(j,1,n)
	suma[j][i]=dpa[j][i+x];
	rep(i,1,x)
	sumb[n][i]=dpb[n][i];
	sumb[n][0]=1;
	rep(i,0,x)
	{
		rep(j,1,n)
		if(a[j]>i)
		(ans+=(ll)suma[j][i]*sumb[n][i])%=mod;
		else break;
	}
	printf("%lld\n",ans);
	return 0;
}



