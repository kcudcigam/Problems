#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 200005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
int N,M,l1,r1,l2,r2,len,A[maxn],B[maxn];

inline int read(){
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline int check(int x){
	int t1=lower_bound(A+l1,A+r1+1,x)-A-l1;
	int t2=lower_bound(B+l2,B+r2+1,x)-B-l2;
	return t1+t2-len/2;
}
inline bool calc(int x){
	int t1=upper_bound(A+l1,A+r1+1,x)-A-l1;
	int t2=upper_bound(B+l2,B+r2+1,x)-B-l2;
	return (t1+t2)>len/2;
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	N=read(),M=read();
	for(int i=1;i<=N;i++) A[i]=read();
	for(int i=1;i<=N;i++) B[i]=read();
	while(M--){
		int opt=read();
		if(opt==1){
			int x=read(),y=read(),z=read();
			(x==0)?A[y]=z:B[y]=z;
		}
		else{
			l1=read(),r1=read(),l2=read(),r2=read();
			len=r1-l1+r2-l2+2;
			int l=l1,r=r1,ans=0,res=0;
			while(l<=r){
				int mid=(l+r)>>1,tp=check(A[mid]);
				if(tp<=0) ans=A[mid],res=tp,l=mid+1;
				else r=mid-1;
			}
			if(res==0 || calc(ans)) printf("%d\n",ans);
			else{
				l=l2,r=r2,ans=0;
				while(l<=r){
					int mid=(l+r)>>1;
					if(check(B[mid])<=0) ans=B[mid],l=mid+1;
					else r=mid-1;
				}
				printf("%d\n",ans);
			}
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
