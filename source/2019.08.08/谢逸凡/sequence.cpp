#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define Rep(i,l,k) for(int i=l;i>=k;i--)
#define ll long long
using namespace std;
const int N=1e5+5;
int ans;
ll ldf[N],a[N],n,m;
template <typename T> void read(T &x){
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for (; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
int main(){
	read(n),read(m);
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	while(m--){
		ll l,r,s,e;read(l),read(r),read(s),read(e);
		ll d=(e-s)/(r-l);
		if(d==0){
			a[l]+=s;l++;while(l<=r) a[l]+=s,l++;
		}
		else{
			a[l]+=s;l++;while(l<=r) a[l]=a[l-1]+d,l++;
		}
//		rep(i,1,n) cout<<a[i]<<" ";cout<<"\n";
	}
	rep(i,1,n) ans^=a[i];
	printf("%d",ans);
	return 0;
}
