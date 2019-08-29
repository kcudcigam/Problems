#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define go(i,u) for(int i=head[u];i;i=nex[i]
using namespace std;
typedef long long ll;
const int mod=1e9+7;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	srand(time(NULL));
	ll x=rand();
	printf("%lld\n",(x*x%mod*x*mod)*x%mod);
	return 0;
}



