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
ll f[310][310];
const ll MOD=1e9+7;
inline ll dfs(int n,int m){
	if(f[n][m])return f[n][m];
	ll ans=0;
	F(i,1,n-1){ans+=(dfs(i,m)*dfs(n-i,m))%MOD;ans%=MOD;}
	F(i,1,m-1){ans+=(dfs(n,i)*dfs(n,m-i))%MOD;ans%=MOD;}
	return f[n][m]=ans;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;read(n);read(m);
	f[1][1]=1;
	writeln(dfs(n,m));
	return 0;
}

