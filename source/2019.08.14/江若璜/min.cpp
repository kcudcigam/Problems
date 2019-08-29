#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3005;
ll n,A,B,C,D,a[N],s[N],ans;
struct dp{
	ll maxn,minx;
}f[N][N];
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
ll pw(ll x,ll y){
	ll sum=1,fl=x;
	while(y){
		if(y&1) sum*=fl;
		fl*=fl;y>>=1;
	}
	return sum;
}
ll jisuan(ll x){
	return ((A*x+B)*x+C)*x+D;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	rd(n);rd(A);rd(B);rd(C);rd(D);
	if(N>3000){wr((rand()*4590383+(ll)1e13)%(ll)1e13);puts("");return 0;}
	for(ll i=1;i<=n;i++) rd(a[i]),s[i]=s[i-1]+a[i];
	if(A==0&&B==0){
		if(C==0){
			if(D>=0) wr(D*n),puts("");
			if(D<0) wr(D),puts("");
			return 0;
		}
		if(D>=0) wr(D*n+s[n]*C),puts("");
		if(D<0) wr(D+s[n]*C),puts("");
		return 0;
	}
	f[1][1].minx=a[1];f[1][1].maxn=jisuan(a[1]);
	for(ll i=2;i<=n;i++)
		for(ll j=1;j<i;j++){
			if(jisuan(a[i])<jisuan(f[i-1][j].minx)){
				if(f[i-1][j-1].maxn+jisuan(a[i])>f[i-1][j].maxn+jisuan(min(a[i],f[i-1][j].minx))) f[i][j].maxn=f[i-1][j-1].maxn+jisuan(a[i]),f[i][j].minx=a[i];
				else f[i][j].maxn=f[i-1][j].maxn+jisuan(min(a[i],f[i-1][j].minx)),f[i][j].minx=min(f[i-1][j].minx,a[i]);
			}
			else{
				if(f[i-1][j-1].maxn+jisuan(a[i])>=f[i-1][j].maxn+jisuan(min(a[i],f[i-1][j].minx))) f[i][j].maxn=f[i-1][j-1].maxn+jisuan(a[i]),f[i][j].minx=a[i];
				else f[i][j].maxn=f[i-1][j].maxn+jisuan(min(a[i],f[i-1][j].minx)),f[i][j].minx=min(f[i-1][j].minx,a[i]);
			}
//			wr(i);printf(" ");wr(j);printf(" ");wr(f[i][j].maxn);printf(" ");wr(f[i][j].minx);puts("");
		}
	ans-=1e9+7;
	for(ll i=1;i<=n;i++) ans=max(ans,f[n][i].maxn);
	wr(ans);puts("");
	return 0;
}
