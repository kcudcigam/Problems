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
const ll MOD=998244353;
inline ll ksm(ll x,ll y){
	ll k=1;
	if(y<0)return 0;
	while(y){
		if(y&1)k=k*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return k;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ll n;read(n);
	string s;cin>>s;
	ll l=s.size();
	ll ans1=ksm(26,n);
	ll ans2=(ksm(26,n-l)+(l*25%MOD)*ksm(26,n-l-1)%MOD)%MOD;
	writeln((ans1+MOD-ans2)%MOD);
	return 0;
}

