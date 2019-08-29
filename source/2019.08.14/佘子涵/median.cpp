#include<cstdio>
#include<iostream>
using namespace std;
const int N=500010;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,m,a[2][N],pd,x,y,z,l,r;
int fi(int i,int l,int r,int x){
	if(a[i][r]<x) return r-l+1;
	if(a[i][l]>=x) return 0;
	int mid=(l+r)>>1;
	return fi(i,l,mid,x)+fi(i,mid+1,r,x);
}
int fi1(int i,int l,int r,int x){
	if(a[i][l]>x) return r-l+1;
	if(a[i][r]<=x) return 0;
	int mid=(l+r)>>1;
	return fi1(i,l,mid,x)+fi1(i,mid+1,r,x);
}
int so(int l,int r,int x,int y,int nu){
	if(l>r) return a[1][x+nu-1];
	if(x>y) return a[0][l+nu-1];
	if(nu==1) return min(a[0][l],a[1][x]);
	int sz1=r-l+1,sz2=y-x+1;
	if(nu==sz1+sz2) return max(a[0][r],a[1][y]);
	if(sz1<=sz2){
		int mid=(y+x)>>1;
		int mu=fi(0,l,r,a[1][mid]);
		int mu1=fi1(0,l,r,a[1][mid]);
		int mu2=fi(1,x,y,a[1][mid]);
		int mu3=fi1(1,x,y,a[1][mid]);
		if(mu+mu2<nu&&mu1+mu3<=sz1+sz2-nu) return a[1][mid];
		if(mu+mu2>=nu) return so(l,l+mu-1,x,x+mu2-1,nu);
		if(mu+mu2<nu) return so(r-mu1+1,r,y-mu3+1,y,mu1+mu3-(sz1+sz2-nu));
	}
	if(sz1>sz2){
		int mid=(l+r)>>1;
		int mu=fi(0,l,r,a[0][mid]);
		int mu1=fi1(0,l,r,a[0][mid]);
		int mu2=fi(1,x,y,a[0][mid]);
		int mu3=fi1(1,x,y,a[0][mid]);
		if(mu+mu2<nu&&mu1+mu3<=sz1+sz2-nu) return a[0][mid];
		if(mu+mu2>=nu) return so(l,l+mu-1,x,x+mu2-1,nu);
		if(mu+mu2<nu) return so(r-mu1+1,r,y-mu3+1,y,mu1+mu3-(sz1+sz2-nu));
	}
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[0][i]);
	for(int i=1;i<=n;i++) read(a[1][i]);
	for(int i=1;i<=m;i++){
		read(pd);
		if(pd==1){
			read(x);read(y);read(z);
			a[x][y]=z;
			continue;
		}
		if(pd==2){
			read(l);read(r);read(x);read(y);
			printf("%d\n",so(l,r,x,y,(r-l+y-x+3)/2));
		}
	}
	return 0;
}
