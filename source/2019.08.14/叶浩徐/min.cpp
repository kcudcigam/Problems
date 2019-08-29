#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
template <typename T> inline void print(T x){
	write(x); putchar(' ');
}
ll sb[4];
ll f(ll x){
	ll p=1;
	ll ans=0;
	for (int i=0;i<=3;i++){
		ans+=sb[i]*p; p*=x;
	}
	return ans;
}
struct node{
	ll s,mi;
}a[200010],b[200010];
ll sum(int x,int y){
	ll ans=LONG_LONG_MAX;
	for (int i=x;i<=y;i++){
		ans=min(ans,a[i].mi);
	}
	return f(ans);
}

ll g[1100][1100];
ll dp(int x,int y){
	if (g[x][y]) return g[x][y];
	g[x][y]=sum(x,y);
	for (int i=x;i<y;i++){
		g[x][y]=max(g[x][y],dp(x,i)+dp(i+1,y));
	}
	return g[x][y];
}
ll n,ans;
int main(){
	fre("min")
	read(n);
	for (int i=3;i>=0;i--) read(sb[i]);
	if (n<=500){
		for (int i=1;i<=n;i++){
			read(a[i].mi);
			a[i].s=f(a[i].mi);
			b[i]=a[i];
			g[i][i]=a[i].s;
		}
		writeln(dp(1,n));
		return 0;
	}
	for (int i=1;i<=n;i++){
		read(a[i].mi);
		a[i].s=f(a[i].mi);
		b[i]=a[i];
	}
	for (int i=2;i<=n;i++){
		ll p=f(min(a[i-1].mi,a[i].mi));
		if (p>=a[i].s+a[i-1].s){
			a[i].mi=min(a[i-1].mi,a[i].mi);
			a[i].s=p;
		}else ans+=a[i-1].s;
	}
	ans+=a[n].s;
	writeln(ans);
	return 0;
}

