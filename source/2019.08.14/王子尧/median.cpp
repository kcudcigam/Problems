#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int n,m;
int a[500010];int b[500010];int c[500010];
inline int num(int l1,int r1,int l2,int r2,int x){
	int l=l1;int r=r1;int n1=l1-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]<x){n1=mid;l=mid+1;}
		else{r=mid-1;}
	}
	n1=n1-l1+1;
	l=l2;r=r2;int n2=l2-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid]<x){n2=mid;l=mid+1;}
		else{r=mid-1;}
	}
	n2=n2-l2+1;
	return n1+n2;
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	
	rep(i,1,m){
		int tmp,l1,r1,l2,r2;read(tmp);
		if(tmp==1){
			read(l1);read(r1);read(l2);
			if(!l1){a[r1]=l2;}
			else{b[r1]=l2;}
		}else{
			read(l1);read(r1);read(l2);read(r2);
			int tmp=r1-l1+1+r2-l2+1;tmp=(tmp+1)/2;
			int l=min(a[l1],b[l2]);int r=max(a[r1],b[r2]);int ans=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(num(l1,r1,l2,r2,mid)<=tmp-1){ans=mid;l=mid+1;}
				else{r=mid-1;}
			}
			write(ans);
		}
	}
	return 0;
} 
