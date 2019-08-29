#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar(48); if (x<0) x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
typedef long long ll;
ll A,B,C,D;
int n;
ll F(int x){
	return A*x*x*x+B*x*x+C*x+D;
}
const ll INF=1e18;
ll a[MAXN];
ll f[MAXN][MAXN]; 
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(A),read(B),read(C),read(D);
	for (int i=1;i<=n;i++)read(a[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			ll mn=INF;
			for (int k=i-1;k>=0;k--){
				mn=min(mn,a[k+1]);
				f[i][j]=max(f[i][j],f[k][j-1]+F(mn));
			}
		}
	}
	ll ans=-INF;
	for (int i=1;i<=n;i++)ans=max(ans,f[n][i]);
	write(ans);
	return 0;
}
/*
5 0 0 1 10
9 9 5 2 6
*/
