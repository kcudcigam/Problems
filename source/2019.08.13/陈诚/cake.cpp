#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9 + 7;
template <typename T> inline void rd(T &x)
{
	x=0; char ch=0; int f=1;
	for(;!isdigit(ch); ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48);return;}
	wrote(x/10);
	putchar(x%10+48);
}
int f[303][303],n,m;
ll dfs(int n,int m)
{
	if(f[n][m]) return f[n][m];
	ll cnt=0;
	for(int i=1; i<n; ++i) cnt=(cnt+dfs(i,m)*dfs(n-i,m))%P;
	for(int i=1; i<m; ++i) cnt=(cnt+dfs(n,i)*dfs(n,m-i))%P;
	return f[n][m]=cnt;
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	rd(n); rd(m);
	f[1][1]=f[1][2]=f[2][1]=1;
	wrote(dfs(n,m));
	puts("");
	return 0;
}
