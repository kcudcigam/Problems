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
ll a[501000],cf[501000];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;read(n);read(m);
	ll ans=0;
	F(i,1,m){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		int gc=(e-s)/(r-l);
		a[l]=s;
		a[r+1]=-e;
		cf[l+1]=gc;
		cf[r+1]=-gc;
	}
	F(i,1,n)cf[i]+=cf[i-1];
	F(i,1,n)a[i]+=a[i-1]+cf[i];
	F(i,1,n)ans^=a[i];
	writeln(ans);
	return 0;
}

