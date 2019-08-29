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
const ll MOD=1e9+7;
ll f1[21000],f2[21000],a[21000];
int b[21000],c[21000],used[21000],n,x;
inline void dp1(){
	f1[0]=1;
	F(i,1,n){
		F(j,0,a[n])used[j]=f1[j];
		F(j,a[i],a[n])
			if(f1[j-a[i]]){
				f1[j]=(f1[j]+f1[j-a[i]])%MOD;
				if(a[i]*(c[i]+1)<=j)f1[j]=(f1[j]+MOD-used[j-a[i]*(c[i]+1)])%MOD;
			}
	}
}
inline void dp2(){
	f2[0]=1;
	DF(i,n,1){
		F(j,0,x+a[i]-1)used[j]=f2[j];
		F(j,a[i],x+a[i]-1){
			if(f2[j-a[i]]){
				f2[j]=(f2[j]+f2[j-a[i]])%MOD;
				if(a[i]*(b[i]+1)<=j)f2[j]=(f2[j]+MOD-used[j-a[i]*(b[i]+1)])%MOD;
			}
		}
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(x);
	F(i,1,n){read(a[i]);read(b[i]);read(c[i]);}
	dp1();
	dp2();
	ll ans=0;
	F(i,x,x+a[n]){ans+=(f1[i-x]*f2[i])%MOD;ans%=MOD;}
	writeln(ans);
	return 0;
}

