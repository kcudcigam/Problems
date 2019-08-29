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
const int N=1e7+5;
ll a[N];
ll solve(int n,int p)
{
	a[1]=0;
	a[2]=2;
	rep(i,3,n)
	a[i]=(a[i-1]*i+(ll)i*(i-1)-((i&1)^1)*(i-2))%p;
	return a[n];
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int n,q,p;
	read(q);
	while(q--)
	{
		read(n);
		read(p);
		printf("%lld\n",solve(n,p));
	}
	return 0;
}


