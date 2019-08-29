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
	if(x<0){putchar('-');x=-x;}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
int a[501000],b[501000];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;read(n);read(m);
	F(i,1,n)read(a[i]);F(i,1,n)read(b[i]);
	F(i,1,m){
		int opt;read(opt);
		if(opt==1){
			int x,y,z;read(x);read(y);read(z);
			if(x==0)a[y]=z;
			if(x==1)b[y]=z;
		}
		if(opt==2){
			int l1,r1,l2,r2;read(l1);read(r1);read(l2);read(r2);
			int k=((r1-l1+1)+(r2-l2+1)+1)>>1;
			int l=l1,r=r1,f=0,ans;
			while(l<=r){
				int mid=(l+r)>>1;
				int le=l2,re=r2,ans2=0;
					while(le<=re){
						int mm=(le+re)>>1;
						if(b[mm]<a[mid]){ans2=mm-l2+1;le=mm+1;}
						else re=mm-1;
					}
				le=l2,re=r2;int ans3=0;
					while(le<=re){
						int mm=(le+re)>>1;
						if(b[mm]<=a[mid]){ans3=mm-l2+1;le=mm+1;}
						else re=mm-1;
					}
				if(ans2+mid-l1+1<=k&&ans3+mid-l1+1>=k){f=1;ans=mid;break;}
				if(ans3+mid-l1+1<k)l=mid+1;
				else r=mid-1;
			}
			if(f){writeln(a[ans]);continue;}
			l=l2;r=r2;
			while(l<=r){
				int mid=(l+r)>>1;
				int le=l1,re=r1,ans2=0;
					while(le<=re){
						int mm=(le+re)>>1;
						if(a[mm]<b[mid]){ans2=mm-l1+1;le=mm+1;}
						else re=mm-1;
					}
				le=l1,re=r1;int ans3=0;
					while(le<=re){
						int mm=(le+re)>>1;
						if(a[mm]<=b[mid]){ans3=mm-l1+1;le=mm+1;}
						else re=mm-1;
					}
				if(ans2+mid-l2+1<=k&&ans3+mid-l2+1>=k){f=1;ans=mid;break;}
				if(ans3+mid-l2+1<k)l=mid+1;
				else r=mid-1;
			}
			if(f){writeln(b[ans]);continue;}
		}
	}
	return 0;
}

