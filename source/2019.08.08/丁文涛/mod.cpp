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
vector <LL> F;
LL T,n,p;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	T=qread();
	while(T--){
		n=qread(),p=qread();
		F.resize(n+3);
		up(1,n,i) F[i]=-1; F[1]=0;
		up(2,n,i) F[i]=(LL)i*(i-1)%p+i*p-(i&1?0:(i-2))+(LL)i*F[i-1]%p;
		printf("%lld\n",F[n]%p);
	}
	return 0;
}
/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 3

*/
