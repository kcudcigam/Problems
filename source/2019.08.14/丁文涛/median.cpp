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
const int MAXN =5e5+3;
int n,q,A[MAXN],B[MAXN],C[MAXN*2];
int calc(int a,int b,int c,int d){
	int p1=0,p2=c,k1=1,k2=1,l=b-a+1+d-c+1,cnt=0;
	while(k1){
		if(p1+k1>1e9) k1>>=1; else{
			k2=1,p2=a-1,cnt=0;
			while(k2){
				if(p2+k2<=b&&A[p2+k2]<p1+k1)
				p2+=k2,k2<<=1; else k2>>=1;
			} cnt+=p2-a+1;
			k2=1,p2=c-1;
			while(k2){
				if(p2+k2<=d&&B[p2+k2]<p1+k1)
				p2+=k2,k2<<=1; else k2>>=1;
			} cnt+=p2-c+1;
			if(cnt<=l/2)
			p1+=k1,k1<<=1; else k1>>=1;
		}
	}
	return p1;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=qread(),q=qread();
	up(1,n,i) A[i]=qread();
	up(1,n,i) B[i]=qread();
	up(1,q,i){
		if(qread()==1){
			int op=qread(),p=qread(),k=qread();
			if(op) B[p]=k; else A[p]=k;
		}
		else {
			int l1=qread(),r1=qread(),l2=qread(),r2=qread();
			printf("%d\n",calc(l1,r1,l2,r2));
		}
	}
	return 0;
} 
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
