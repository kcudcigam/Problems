#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
typedef long long ll;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if(ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
ll a[MAXN];
int n,m;
int getAns(){
	ll ans=a[1];
//	for (int i=1;i<=n;i++)
//		printf("%d ",a[i]);
//	puts("");
	for (int i=2;i<=n;i++)
		ans^=a[i];
	return ans;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	memset(a,0,sizeof(a));
	for (int i=1;i<=m;i++){
		ll s,e;
		int l,r;
		read(l),read(r);
		read(s),read(e);
		ll tmp=s,x=(e-s)/(r-l);
		for (int j=l;j<=r;j++)
			a[j]+=tmp,tmp+=x;
//		printf("%d\n",getAns());
	}
	printf("%d\n",getAns());
	return 0;
}
