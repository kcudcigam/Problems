#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if(ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
typedef long long ll;
const ll INF=1e15;
ll a[MAXN];
ll dpl[MAXN],dpr[MAXN],ansl[MAXN],ansr[MAXN];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;read(n);
	for (int i=1;i<=n;i++)
		read(a[i]);
	ansl[0]=-INF;
	for (int i=1;i<=n;i++){
		dpl[i]=max(dpl[i-1]+a[i],a[i]);
		ansl[i]=max(ansl[i-1],dpl[i]);
	}
	ansr[n+1]=-INF;
	for (int i=n;i>=1;i--){
		dpr[i]=max(dpr[i+1]+a[i],a[i]);
		ansr[i]=max(ansr[i+1],dpr[i]);
	}
	ll ans=-INF;
	for (int i=2;i<=n;i++)
		ans=max(ans,ansl[i-1]+ansr[i]);
	printf("%lld\n",ans);
	return 0;
}
