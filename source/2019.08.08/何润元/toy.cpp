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
int a[1010],f[1010][2];
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	int n,m,ans=0;read(n);read(m);
	f[0][0]=m;
	F(i,1,n)read(a[i]);
	F(i,1,n)
		DF(j,i-1,0){
			f[j+1][0]=f[j+1][1];
			if(f[j][0]-a[i]>=0){
				int k=f[j][0]-a[i];
				if(k>f[j+1][1]){f[j+1][1]=k;checkmax(ans,j+1);}
			}
		}
	writeln(ans);
	return 0;
}
