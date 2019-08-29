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
int f[110][110];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll y;read(y);
	int n=64,m=64;
	F(i,1,n)f[i][n]=1;
	if(y==0){cout<<2<<' '<<0<<endl;return 0;}
	if(y==1){cout<<2<<' '<<1<<endl<<1<<' '<<2<<endl;return 0;}
	ll x=1;
	int op;
	F(i,2,n){x=x*2;if(x>=y){op=i;break;}}
	F(i,1,op-2)
		F(j,i+1,op-1){
			f[i][j]=1;
			m++;
		}
	x/=2;
	y-=x;
	x/=2;
	DF(i,op-1,2){
		if(y-x>=0){y-=x;f[i][op]=1;m++;}
		x/=2;
	}
	if(y>0){f[1][op]=1;m++;}
	writes(n);writeln(m);
	F(i,1,n)
		F(j,i+1,n)
			if(f[i][j]){writes(i);writeln(j);}
	return 0;
}
