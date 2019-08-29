#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"-------------"<<endl;

inline int read(){
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF = 1000483600;
const int MAXN = 500010;

int N,M; int a[MAXN+1],b[MAXN+1];

inline int check1(int k,int l1,int r1,int l2,int r2){
	int p=((r1-l1+1+r2-l2+1+1)>>1)-(k-l1+1); p=p+l2-1;
	int d,d2; if(p>r2) d=INF; else if(p<l2) d=-1; else d=b[p];
	++p; if(p>r2) d2=INF; else if(p<l2) d2=-1; else d2=b[p];
	if(d<=a[k]&&a[k]<=d2) return 2;
	else if(a[k]<=d) return 0;
	else return 1;
}
inline int check2(int k,int l1,int r1,int l2,int r2){
	int p=((r1-l1+1+r2-l2+1+1)>>1)-(k-l2+1); p=p+l1-1;
	int d,d2; if(p>r1) d=INF; else if(p<l1) d=-1; else d=a[p];
	++p; if(p>r1) d2=INF; else if(p<l1) d2=-1; else d2=a[p];
	if(d<=b[k]&&b[k]<=d2) return 2;
	else if(b[k]<=d) return 0;
	else return 1;
}


int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	N=read(),M=read();
	for(int i=1;i<=N;i++) a[i]=read();
	for(int i=1;i<=N;i++) b[i]=read();
	while(M--){
		int opr=read();
		if(opr==1){
			int x=read(),y=read(),z=read();
			if(x==1) b[y]=z; else a[y]=z; 
		} else{
			int l1=read(),r1=read(),l2=read(),r2=read();
			int md=((r1-l1+1+r2-l2+1+1)>>1);
			int l=l1,r=r1,ret=0;
			while(l<=r){
				int mid=(l+r)>>1; int p=check1(mid,l1,r1,l2,r2);
				//cout<<l<<" "<<r<<": "<<mid<<" "<<p<<endl;
				if(p==0) l=mid+1;
				else if(p==1) r=mid-1;
				else {ret=mid; break;}
			}
			if(ret){
				printf("%d\n",a[ret]);
				continue;
			}
			l=l2,r=r2;
			while(l<=r){
				int mid=(l+r)>>1; int p=check2(mid,l1,r1,l2,r2);
				if(p==0) l=mid+1;
				else if(p==1) r=mid-1;
				else {ret=mid; break;}
			}
			printf("%d\n",b[ret]);
		}
	}
	return 0;
}

