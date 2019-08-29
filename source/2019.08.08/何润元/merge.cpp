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
int n,fa[501000],sum[501000],ls[501000],rs[501000];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
inline void work(int x){if(x>n){sum[ls[x]]+=sum[x];sum[rs[x]]+=sum[x];work(ls[x]);work(rs[x]);}}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int q;read(n);read(q);
	F(i,1,n)fa[i]=i;
	int now=n;
	F(i,1,q){
		int k;read(k);
		if(k==1){
			int x,y;
			read(x);read(y);
			if(get(x)==get(y))continue;
			now++;fa[now]=now;
			ls[now]=get(x);
			rs[now]=get(y);
			merge(x,now);
			merge(y,now);
		}
		else {
			int a,b;
			read(a);read(b);
			sum[get(a)]+=b;
		}
	}
	work(now);
	F(i,1,n-1)writes(sum[i]);
	writeln(sum[n]);
	return 0;
}

