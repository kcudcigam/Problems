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
int a[10010],s,ans;
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	int n,k;read(n);read(k);
	int t=0,x=n;
	while(x){
		t++;
		a[t]=x&1;
		s+=a[t];
		x>>=1;
	}
	cout<<s<<endl;
	if(s<=k){puts("0");return 0;}
	F(i,1,t-1){
		if(a[i]==1){
			ans+=1<<(i-1);
			a[i+1]++;
			a[i]=0;
			if(a[i+1]==2)s--;
		}
		if(a[i]==2){
			a[i+1]++;
			a[i]=0;
			if(a[i+1]==2)s--;
		}
		if(s<=k){writeln(ans);return 0;}
	}
	return 0;
}


