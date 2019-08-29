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
int qread(){
	int ret,c,w=1;
	while((c=getc())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getc())>='0'&&c<='9')
	ret=ret*10+c-'0';
	return ret*w;
}
const int MAXN =1e5+3;
int sum,ans=-INF,flag,n,data[MAXN],P[MAXN],Q[MAXN];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=qread();
	up(1,n,i) data[i]=qread();
	flag=sum=0; up(1,n,i){
		if((sum+=data[i])<0) sum=0;
		if(sum>flag) flag=sum;
		P[i]=flag;
	}
	flag=sum=0; dn(n,1,i){
		if((sum+=data[i])<0) sum=0;
		if(sum>flag) flag=sum;
		Q[i]=flag;
	}
	up(1,n-1,i) ans=max(ans,P[i]+Q[i+1]);
	printf("%d\n",ans);
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3
*/
