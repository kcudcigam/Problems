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
const ll mod=1000000007;
ll f[310][310];
ll d(ll x,ll y){
	if (f[x][y]) return f[x][y];
	for (int i=1;i<x;i++) f[x][y]+=d(i,y)*d(x-i,y)%mod;
	for (int i=1;i<y;i++) f[x][y]+=d(x,i)*d(x,y-i)%mod;
	f[x][y]%=mod;
	return f[x][y];
}
ll n,m;
int main(){
	fre("cake")
	read(n); read(m);
	f[1][1]=1;
	writeln(d(n,m));
	return 0;
}

