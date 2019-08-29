#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
LL P,n,m;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	P=R();
	n=64;m=1953;
	F(i,0,60)if((P>>i)&1)++m;
	cout<<n<<' '<<m<<'\n';
	F(i,2,63)
		F(j,1,i-1){
			cout<<j<<' '<<i<<'\n';
			++m;
		}
	F(i,0,60)if((P>>i)&1)cout<<i+2<<' '<<64<<'\n';
	return 0;
}
