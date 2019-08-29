#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar(48); if (x<0) x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
int a[MAXN],b[MAXN];
int solve(int l1,int r1,int l2,int r2,int k){
//	cerr << l1 << " " << r1 << " " << l2 << " " << r2 << " " << k << endl;
	if (l1>r1){
		return b[l2+k-1];
	}
	if (l2>r2){
		return a[l1+k-1];
	}
	int mid=(l1+r1)>>1;
	int p=upper_bound(b+l2,b+r2+1,a[mid])-b-1;
//	cerr << p << endl;
	if (p==r2){
		if (l1==r1)
			return k==r2-l2+2?a[l1]:b[k+l2-1];
	}
	if (p==l2-1){
		if (l1==r1) return k==1?a[l1]:b[l2+k-2];
	}
	if (k<=p-l2+mid-l1+2) return solve(l1,mid,l2,p,k);
	else return solve(mid+1,r1,p+1,r2,k-(p-l2+1)-(mid-l1+1));
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;read(n),read(m);
	for (int i=1;i<=n;i++)read(a[i]);
	for (int j=1;j<=n;j++)read(b[j]);
	for (int i=1;i<=m;i++){
		int opt,l1,r1,l2,r2,x,y,z;read(opt);
		if (opt==1){
			read(x),read(y),read(z);
			if (x==0)a[y]=z;else b[y]=z;
		}else{
			read(l1),read(r1),read(l2),read(r2);
			int k=(r1-l1+1+r2-l2+2)/2;
			write(solve(l1,r1,l2,r2,k));putchar('\n');
		}
	}
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/
