#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define M make_pair
#define P pair
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	ull y=0;
	T l=0;
	if(!x){putchar(48);return;}
	if(x<0){x=-x;putchar('-');}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
ll a[101000],s1[101000],s2[101000],nu1[101000],nu2[101000];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;read(n);
	ll ans=-INT_MAX;
	F(i,1,n){read(a[i]);s1[i]=s2[i]=-INT_MAX;}s1[0]=s2[n+1]=-INT_MAX;
	F(i,1,n){checkmax(s1[i],max(s1[i-1],nu1[i-1]+a[i]));nu1[i]=nu1[i-1]+a[i];if(nu1[i]<0)nu1[i]=0;}
	DF(i,n,1){checkmax(s2[i],max(s2[i+1],nu2[i+1]+a[i]));nu2[i]=nu2[i+1]+a[i];if(nu2[i]<0)nu2[i]=0;}
	F(i,1,n-1)checkmax(ans,s1[i]+s2[i+1]);
	writeln(ans);
	return 0;
}

