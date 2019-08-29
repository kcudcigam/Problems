#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=305,mod=1000000007;
ll n,m,f[N][N];
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
ll qiege(ll x,ll y){
	if(f[x][y]!=0) return f[x][y];
	if(f[y][x]!=0) return f[y][x];
	for(ll i=1;i<x;i++) f[x][y]=(f[x][y]+(qiege(i,y)*qiege(x-i,y))%mod)%mod;
	for(ll i=1;i<y;i++) f[x][y]=(f[x][y]+(qiege(x,i)*qiege(x,y-i))%mod)%mod;
	f[y][x]=f[x][y];
	return f[x][y];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	rd(n);rd(m);f[1][1]=1;
	wr(qiege(n,m));puts("");
	return 0;
}
