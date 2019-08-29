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
int f[17][17][17][17],ff[17][17][17][17],d[21],s,a[21];
inline int work(int i,int j,int k,int l){
	if(f[i][j][k][l]==1)return 1;
	if(f[i][j][k][l]==-1)return -1;
	if(ff[i][j][k][l]==s){f[i][j][k][l]=1;return 1;}
	ff[i][j][k][l]=s;
	d[1]=i;d[2]=j;d[3]=k;d[4]=l;
	int f2=0;
	F(ii,1,4){
		if(d[ii]==1){d[ii]=0;f2=1;}
		if(d[ii]>1){
			d[ii]--;
			F(jj,1,4)if(d[jj]==0){d[jj]=a[d[ii]];break;}
		}
	}
	if(f2){f[i][j][k][l]=work(d[1],d[2],d[3],d[4]);return f[i][j][k][l];}
	else {f[i][j][k][l]=-1;return -1;}
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	int n,ans=0;read(n);
	F(i,1,n-1)read(a[i]);
	f[0][0][0][0]=-1;
	s++;
	F(i,0,n)
		F(j,0,n)
			F(k,0,n)
				F(l,0,n){
					s++;
					if(work(i,j,k,l)==1)ans++;
				}
	writeln(ans);
	return 0;
}
