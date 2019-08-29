#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
const int INF =2147483647;
const int SIZ =1e3;
typedef long long LL;
char bef[SIZ+3],*p1=bef,*p2=bef;
char getc(){
	if(p1==p2) p1=bef,p2=bef+fread(bef,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
} 
LL qread(){
	LL ret,c,w=1;
	while((c=getc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =5e5+3;
LL n,m,sum,ans;
LL delta1[MAXN],delta2[MAXN];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=qread(),m=qread();
	up(1,m,i){
		int l=qread(),r=qread(),a=qread(),b=qread();
		int t=(b-a)/(r-l),_t=a-t;
		delta2[l]+=_t,delta2[r+1]-=_t;
		delta1[l]+=t,delta1[r+1]-=t;
		delta1[r+1]-=(r-l+1)*t,delta1[r+2]+=(r-l+1)*t;
	}
	sum=0; up(1,n,i) sum+=delta1[i],delta2[i]+=sum;
	sum=0; up(1,n,i) sum+=delta2[i],ans^=sum;
	printf("%lld\n",ans);
	return 0;
}
/*
5 2
1 5 -2000000000 2000000000
1 5 -2000000000 2000000000
*/
