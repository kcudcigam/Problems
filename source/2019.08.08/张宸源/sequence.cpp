#include<bits/stdc++.h>
#define il inline
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;i++)
#define Rep(i,x,y) for(re int i=x;i>=y;i--)
#define ll long long
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
template <typename T> il void read(T &x)
{
	int f=1;
	x=0;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
il void rea(int&x,int&y)
{
	read(x),read(y);
}
const int N=500005;
ll a[N],c[N],ans;
int n,m;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	rea(n,m);
	int l,r,s,e;
	rep(i,1,m)
	{
		rea(l,r),rea(s,e);
		int t=(e-s)/(r-l);
		a[l]+=s,a[r+1]-=e;
		c[l+1]+=t,c[r+1]-=t;
	}
	rep(i,1,n)
	c[i]+=c[i-1];
	rep(i,1,n)
	a[i]+=a[i-1]+c[i];
	rep(i,1,n)
	ans^=a[i];
	printf("%lld\n",ans);
	return 0;
}

