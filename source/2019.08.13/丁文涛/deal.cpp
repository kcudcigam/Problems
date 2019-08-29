#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
const int INF =2147483647;
const int SIZ =1e3;
const int P	=1e9+7;
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
const int MAXN =1e3+3,MAXM=2*1e4+3;
int n,X,A[MAXN],B[MAXN],C[MAXN];
int F[MAXM],G[MAXM],T[MAXM],ans;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=qread(),X=qread();
	up(1,n,i){
		A[i]=qread(),B[i]=qread(),C[i]=qread();
	}
	F[0]=G[0]=1;
	dn(n,1,i){
		up(0,A[i]+X-1,j){
			T[j]=F[j];
			if(!B[i]||j-A[i]<0) continue;
			T[j]=((LL)T[j]+T[j-A[i]])%P;
			if(j-(B[i]+1)*A[i]>=0)
			T[j]=((LL)T[j]-F[j-(B[i]+1)*A[i]]+P)%P;
		}
		memcpy(F,T,sizeof(F));
	}
	dn(n,1,i){
		up(0,MAXM-1,j){
			T[j]=G[j];
			if(!C[i]||j-A[i]<0) continue;
			T[j]=((LL)T[j]+T[j-A[i]])%P;
			if(j-(C[i]+1)*A[i]>=0)
			T[j]=((LL)T[j]-G[j-(C[i]+1)*A[i]]+P)%P;
		}
		memcpy(G,T,sizeof(G));
	}
	up(X,MAXM-1,i) ans=((LL)ans+(LL)F[i]*G[i-X])%P;
	printf("%d\n",ans);
	return 0;
} 
