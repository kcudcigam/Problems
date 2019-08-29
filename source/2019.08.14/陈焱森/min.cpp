#include <iostream>
#include <cstdio>
#include <cctype>
#include <climits>
using namespace std;

template <class T_> void read(T_ &x) {
	char ch;bool flag=false;x=0;
	while(!isdigit(ch=getchar()));
		(ch=='-')&&(flag=true);
	do{(x*=10)+=ch-'0';
	}while(isdigit(ch=getchar()));
	(flag)&&(x=-x);
}

#define kl k<<1
#define kr k<<1|1

int t[1000005],a[200005];

void build(int k,int l,int r) {
	if(l==r) {
		t[k]=a[l];return;
	}
	int mid=(l+r)>>1;
	build(kl,l,mid);
	build(kr,mid+1,r);
	t[k]=min(t[kl],t[kr]);
}
int query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return t[k];
	if(y<l||r<x)return INT_MAX;
	int mid=(l+r)>>1;
	int res=query(kl,l,mid,x,y);
	return min(res,query(kr,mid+1,r,x,y));
}

int f[5005][5005];

int main(void) {
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	int n,A,B,C,D;
	read(n);read(A);read(B);read(C);read(D);
	for(int i=1;i<=n;++i)read(a[i]);
	build(1,1,n);
	for(int i=1;i<=n;++i)f[i][i]=A*a[i]*a[i]*a[i]+B*a[i]*a[i]+C*a[i]+D;
	for(int k=2;k<=n;++k) {
		for(int i=1;i<=n-k+1;++i) {
			int j=i+k-1;
			int q=query(1,1,n,i,j);
			f[i][j]=A*q*q*q+B*q*q+C*q+D;
			for(int e=i;e<j;++e)
				f[i][j]=max(f[i][j],f[i][e]+f[e+1][j]);
		}
	}
	printf("%d",f[1][n]);
	
	fclose(stdin);
	fclose(stdout);
}
