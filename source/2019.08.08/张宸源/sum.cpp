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
const int N=100005;
int a[N],n,m;
ll b[N];
bool cmp(int x,int y)
{
	return x>y;
}
bool cmp1(ll x,ll y)
{
	return x>y;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	int su=0;
	rep(i,1,n)
	{
		read(a[i]);
		if(a[i]>0)su++;
	}
	if(su<=2)
	{
		sort(a+1,a+n+1,cmp);
		printf("%d\n",a[1]+a[2]);
	}
	bool fla=(a[1]>0);
	ll s=a[1];
	rep(i,2,n)
	{
		if((a[i]>0)==fla)
		s+=a[i];
		else
		{
			b[++m]=s;
			fla^=1;
			s=a[i];
		}
	}
	b[++m]=s;
	rep(i,2,m-1)
	{
		if(b[i]<0)
		{
			if(b[i-1]>=-b[i]&&b[i+1]>=-b[i])
			b[i+1]+=b[i]+b[i-1],b[i]=b[i-1]=-lnf;
		}
	}
	sort(b+1,b+m+1,cmp1);
	printf("%lld\n",b[1]+max(0ll,b[2]));
	return 0;
}


