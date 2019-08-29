#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define re register int 
const int maxn=500005;
struct node{
	int l2,r2,left2,right2,midum2;
	int l1,r1,left1,right1,midum1;
	#define l2(x) tree[x].l2;
	#define r2(x) tree[x].r2;
	#define mid2(x) tree[x].midum12
	#define l1(x) tree[x].l1;
	#define r1(x) tree[x].r1;
	#define mid1(x) tree[x].midum1;
}tree[3*maxn];
int n,m;
int a[maxn],b[maxn];

inline int read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

void build(int p,int l,int r)
{
	l1(p)=l; r1(p)=r;
	if(l1==r1) {
		mid1(p)=a[l1]; mid2(p)=b[l1]; return ;
	}
	int mid=(l+r)/2;
	  build(p<<1,l,r);
	  build(p<<1|1,mid+1,r);
	if((r-l+1)%2) {
		mid1(p)=a[mid];
		mid2(p)=b[mid];
	}
	else {
		mid1(p)=(mid1(p<<1)+mid1(p<<1|1))/2;
		mid2(p)=(mid2(p<<1)+mid2(p<<1|1))/2;
	}
	
}

ll ask(int p,int l1,int r1,int l2,int r2)
{
	
}

void change(int p,int x,int v,int flag) 
{
	if(l1(p)==r1(p)) {
		if(flag) {
			b[l1]=v; mid2(p)=v;
		}
		else {
			a[l1]=v; mid1(p)=v;
		}  
		return ;
	}
	int mid=l1(p)+r1(p);
	if(x<=mid) change(p<<1,x,v,flag);
	if(x>mid)  change(p<<1|1,x,v,flag);
	mid1(p)=(mid1(p)<<1+mid1(p)<<1|1)/2;
	mid2(p)=(mid2(p)<<1+mid2(p)<<1|1)/2;
}

int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	for(re i=1;i<=n;i++) {
		a[i]=read();
	}
	for(re i=1;i<=n;i++) {
		b[i]=read();
	}
	build(1,1,n);
	while(m--) {
		int flag; flag=read();
		if(flag==1) {
			int x,y,z; 
			x=read(); y=read(); z=read();
			if(x) change(1,y,z,1);
			else  change(1,y,z,0);
		}
		else {
			int l1,r1,l2,r2;
			l1=read(); r1=read(); l2=read(); r2=read();
			ll val1=ask(1,l1,r2);
			ll val2=ask(1,l2,r2);
			if(val1)
		}
	}
}
