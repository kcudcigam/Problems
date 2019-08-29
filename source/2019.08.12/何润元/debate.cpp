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
int s[4],a[4][401000];
inline bool cmp(int x,int y){return x>y;}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n;read(n);
	F(i,1,n){
		string opt;
		cin>>opt;
		int x;read(x);
		if(opt=="11"){s[0]++;a[0][s[0]]=x;}
		if(opt=="01"){s[1]++;a[1][s[1]]=x;}
		if(opt=="10"){s[2]++;a[2][s[2]]=x;}
		if(opt=="00"){s[3]++;a[3][s[3]]=x;}
	}
	F(i,0,3)sort(a[i]+1,a[i]+s[i]+1,cmp);
	int ans=0,s1=0,s2=0;
	F(i,1,s[0]){ans+=a[0][i];s1++;s2++;}
	F(i,1,min(s[1],s[2])){ans+=a[1][i]+a[2][i];s1++;s2+=2;}
	if(s[1]>s[2])F(i,s[2]+1,s[1]){s[3]++;a[3][s[3]]=a[1][i];}
	if(s[1]<s[2])F(i,s[1]+1,s[2]){s[3]++;a[3][s[3]]=a[2][i];}
	sort(a[3]+1,a[3]+s[3]+1,cmp);
	F(i,1,s[3])if(s1*2>=s2+1){ans+=a[3][i];s2++;}
	writeln(ans);
	return 0;
}
