#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define Rep(i,x,y) for(int i=x;i>=y;--i)
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
const int mod=1000000007;
int n,m;
ll a[305][305];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	a[1][1]=1;
	rep(i,1,n)
	rep(j,1,m)
	{
		rep(k,1,i-1)
		(a[i][j]+=a[k][j]*a[i-k][j])%=mod;
		rep(k,1,j-1)
		(a[i][j]+=a[i][k]*a[i][j-k])%=mod;
	}
	printf("%lld\n",a[n][m]);
//	rep(i,1,n)
//	{
//		rep(j,1,m)
//		printf("%10lld",a[i][j]);
//		cout<<endl;
//	}
	return 0;
}



