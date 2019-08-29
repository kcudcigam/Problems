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
ll s[10001000],ss[110],f[110],a[110];
int k;
inline void sheng(int x,int y,int mm,int dep){
	if(dep>mm){k++;s[k]=0;F(i,1,mm)s[k]=s[k]*10+ss[i];}
	else {
		ss[dep]=x;sheng(x,y,mm,dep+1);
		ss[dep]=y;sheng(x,y,mm,dep+1);
	}
}
inline void shengcheng(int x,int y){F(i,1,13)sheng(x,y,i,1);}
inline bool fuhe(ll x){
	int s=0;
	F(i,0,9)f[i]=0;
	while(x>0){
		f[x%10]=1;
		x/=10;
	}
	F(i,0,9)s+=f[i];
	return s<=2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;read(t);
	k=1;
	F(i,0,9)
		F(j,i+1,9)
			shengcheng(i,j);
	ll mx=0;
	F(i,1,t){read(a[i]);checkmax(mx,a[i]);}
	if(mx<=1e13){
		F(i,1,t){
			int s1=0;
			ll x=a[i];
			F(j,0,9)f[j]=0;
			while(x>0){
				f[x%10]=1;
				x/=10;
			}
			F(j,0,9)s1+=f[j];
			if(s1<=2){puts("1");continue;}
			int ff=0;
			F(j,1,k){if(s[j]<=a[i]&&fuhe(a[i]-s[j])){ff=1;break;}}
			if(ff)puts("2");
			else puts("3");
		}
	}
	else {
		F(i,1,t){
			int s=0;
			F(j,0,9)f[j]=0;
			while(a[i]>0){
				f[a[i]%10]=1;
				a[i]/=10;
			}
			F(j,0,9)s+=f[j];
			writeln(s);
		}
	}
	return 0;
}

