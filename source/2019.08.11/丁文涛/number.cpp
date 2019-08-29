#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =INT_MAX;
const int SIZ =1e3;
char bef[SIZ+3],*p1=bef,*p2=bef;
char readc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
LL qread(){
	LL w=1,c,ret;
	while((c=readc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=readc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =3e5+3;
int ans=INF,F[MAXN];
bool check(int x){
	bool vis[10]; memset(vis,0,sizeof(vis));
	int cnt=0;
	while(x){
		if(!vis[x%10]) vis[x%10]=1,cnt++;
		x/=10;
	}
	return cnt<=2;
}
int dp(int x,int len){
	if(F[x]!=INF) return F[x];
	if(check(x)) return F[x]=1;
	if(len>=2) return INF/4;
	int t=0;
	up(1,x,i) F[x]=min(F[x],dp(x-i,len+1)+dp(i,len+1));
	return F[x];
}
LL n,flag;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	
	dn(qread(),1,T){
		LL n=qread();flag=true;
		if(check(n)) puts("1"),flag=false;
		if(flag) dn(n/2,1,i)if(check(i)&&check(n-i)){
			puts("2"),flag=false;
			break;
		}
		if(flag) puts("3");
	}
	return 0;
}
