#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e3;
const int P= 1e9+7;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
int qread(){
	int w=1,c,ret=0;
	while((c=readc())>'9'||c<'0');
	ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0'; 
	return ret*w;
}
const int MAXN =300+3;
int F[MAXN][MAXN],n,m;
int dp(int x,int y){
	if(x>y) swap(x,y);
	if(F[x][y]) return F[x][y];
	up(1,x-1,k) F[x][y]=((LL)F[x][y]+(LL)dp(k,y)*dp(x-k,y))%P;
	up(1,y-1,k) F[x][y]=((LL)F[x][y]+(LL)dp(k,x)*dp(y-k,x))%P;
	return F[x][y]%P;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=qread(),m=qread(),F[1][1]=1;
	printf("%d\n",dp(n,m));
	return 0;
} 
