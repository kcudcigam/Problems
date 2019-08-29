#include<iostream>
#include<cstdio>
#include<algorithm>
#define Inf 500009
using namespace std;
int n,m,k,t,x,y,l,r,total;
int a[Inf],b[Inf],c[2*Inf];
inline int read() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();;
	for(int i=1;i<=m;++i){
		k=read();
		if(k==1){scanf("%d %d %d",&t,&x,&y);if(!t)a[x]=y;if(t)b[x]=y;}
		if(k==2){
			total=0;
			scanf("%d %d %d %d",&x,&y,&l,&r);
			int s=(r-l+y-x+2)/2+1;
			for(int j=x;j<=y;++j) c[++total]=a[j];
			for(int j=l;j<=r;++j) c[++total]=b[j];
			sort(c+1,c+1+total);
			printf("%d\n",c[s]);
		}
	}
	return 0;
}
