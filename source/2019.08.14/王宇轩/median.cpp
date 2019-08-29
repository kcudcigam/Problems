#include<bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m,a[N],b[N],op,x,y,z,l1,l2,r1,r2;
int Calc(int l1,int r1,int l2,int r2){
	int l=min(a[l1],b[l2]),r=max(a[r1],b[r2]),len=(r1-l1+1)+(r2-l2+1),p=len+1>>1;
	while (l<r){
		int mid=l+r>>1,cnt=0;
		cnt+=upper_bound(a+l1,a+r1+1,mid)-a-l1;
		cnt+=upper_bound(b+l2,b+r2+1,mid)-b-l2;
		if (cnt<p) l=mid+1;
		else r=mid;
	}
	return r;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;++i) read(a[i]);
	for (int i=1;i<=n;++i) read(b[i]);
	for (int i=1;i<=m;++i){
		read(op);
		if (op==1){
			read(x);read(y);read(z);
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		else{
			read(l1);read(r1);read(l2);read(r2);
			printf("%d\n",Calc(l1,r1,l2,r2));
		}
	}
	return 0;
}
