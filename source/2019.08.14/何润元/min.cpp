#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define P pair
#define M make_pair
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
	if(x<0){putchar('-');x=-x;}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
ll aa,b,c,d;
ll ha(ll x){return aa*x*x*x+b*x*x+c*x+d;}
ll f[1100],smi[1100][1100],a[210000];
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n;read(n);
	read(aa);read(b);read(c);read(d);
	F(i,1,n)read(a[i]);
	if(aa==b&&aa==0&&c<=0){
		int f=0;
		F(i,1,n)if(a[i]<0){f=1;break;}
		if(f){ll ans=0;F(i,1,n)if(a[i]<0)ans+=ha(a[i]);writeln(ans);}
		else{ll mi=1e18;F(i,1,n)checkmin(mi,a[i]);writeln(ha(mi));}
		return 0;
	}
	F(i,1,n)smi[i][i]=a[i];
	smi[0][0]=1e18;
	F(i,0,n)
		F(j,1,n-i)
			smi[i][i+j]=min(smi[i][i+j-1],a[i+j]);
	F(i,1,n)f[i]=-1e18;
	F(i,1,n)
		F(j,0,i-1)
			checkmax(f[i],f[j]+ha(smi[j+1][i]));
	writeln(f[n]);
	return 0;
}

