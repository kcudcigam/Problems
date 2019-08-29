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
	T l=0;
	ull y=0;
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
ll MOD=1000000007;
ll fac[210000];
int link[2][210000],ss[2][210000],ss2[210000];
bool vis[210000];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;read(num);
	int n,m1,m2;read(n);read(m1);read(m2);
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*1LL*i%MOD;
	F(i,1,m1){
		int x,y;read(x);read(y);
		link[0][x]=y;link[0][y]=x;
	}
	F(i,1,m2){
		int x,y;read(x);read(y);
		link[1][x]=y;link[1][y]=x;
	}
	int sum=0;
	F(i,1,n)
		if(!link[0][i]&&!link[1][i]){vis[i]=1;sum++;}
	ll ans=fac[sum];
	F(i,1,n)
		if(!vis[i]){
			if(!link[0][i]){
				int q=1,p=i,s=1;
				vis[i]=1;
				while(link[q][p]){
					s++;
					p=link[q][p];
					vis[p]=1;
					q=!q;
				}
				ss[0][s]++;
				if(s%2==0)ans=ans*2%MOD;
			}
			if(!link[1][i]){
				int q=0,p=i,s=1;
				vis[i]=1;
				while(link[q][p]){
					s++;
					p=link[q][p];
					vis[p]=1;
					q=!q;
				}
				if(s%2==0)ss[1][s]++;
				else ss[0][s]++;
				if(s%2==0)ans=ans*2%MOD;
			}
		}
	F(i,1,n)
		F(j,0,1)
			ans=ans*fac[ss[j][i]]%MOD;
	F(i,1,n)
		if(!vis[i]){
			int q=1,p=i,s=1;
			vis[i]=1;
			while(link[q][p]!=i){
				s++;
				p=link[q][p];
				vis[p]=1;
				q=!q;
			}
			ss2[s]++;
			ans=ans*s%MOD;
		}
	F(i,1,n)ans=ans*fac[ss2[i]]%MOD;
	writeln((fac[n]+MOD-ans)%MOD);
	return 0;
}

