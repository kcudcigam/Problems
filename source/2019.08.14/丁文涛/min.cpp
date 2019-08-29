#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =2147483647;
inline int qread(){
	register int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=(ret<<3)+(ret<<1)+c-48; return ret*w;
}
const int MAXN =1e3+3,MAXM=2e5+3;
LL a,b,c,d,F[MAXM],G[MAXM],n,tt;
#define f(x) (a*x*x*x+b*x*x+c*x+d)
int ST[20][MAXN];
LL gtmn(int x,int y){
	int len=y-x+1,cnt=0;
	while((1<<cnt)<len) cnt++;
	return min(ST[cnt][x],ST[cnt][y-(1<<cnt-1)]);
}
LL calc(int t){
	if(F[t]!=INF) return F[t];
	else F[t]=f(gtmn(1,t)),G[t]=t;
	up(1,min(tt,t-1ll),k){
		LL ttt=calc(k)+f(gtmn(k+1,t));
		if(ttt>F[t]) F[t]=ttt;
	}
	up(max(1ll,G[t-1]-tt),t-1,k){
		LL ttt=calc(k)+f(gtmn(k+1,t));
		if(ttt>F[t]) F[t]=ttt,G[t]=k;
	}
	return F[t];
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=qread(),a=qread(),b=qread(),c=qread(),d=qread();
	tt=2e7/n;	//面向数据编程 
	up(1,n,i) ST[0][i]=qread(),F[i]=INF;
	up(1,19,j) up(1,n,i) ST[j][i]=min(ST[j-1][i],ST[j-1][i+(1<<j-1)]);
	printf("%lld\n",calc(n));
//	up(1,n,i) printf("%d ",G[i]);
	return 0;
} 
/*
5 0 0 1 10
9 9 5 2 6
*/
