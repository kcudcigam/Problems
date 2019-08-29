#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
#pragma GCC optimize("Ofast")
#define R register
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int le,stk[20];
inline void out(int x){
	if (!x) return putchar('0'),void();
	le=0;
	while (x) stk[le++]=x%10,x/=10;
	while (le--)  putchar(stk[le]+'0');
} 
int a[M],b[M];
int n,m;
inline pair<int,int> qa(int l,int r,int x){
	R int p=lower_bound(a+l,a+r+1,x)-a;
	R int del=0;
	if (a[p]==x && p!=r+1) del=upper_bound(a+l,a+r+1,x)-a-p;
	return make_pair(r-p+1-del,p-l);
}
inline pair<int,int> qb(int l,int r,int x){
	R int p=lower_bound(b+l,b+r+1,x)-b;
	R int del=0;
	if (b[p]==x && p!=r+1) del=upper_bound(b+l,b+r+1,x)-b-p;
	return make_pair(r-p+1-del,p-l);
}
int main(){ 
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	while (m--){
		R int tp=read()-1;
		if (!tp){
			R bool opt=read(); R int x=read(),y=read();
			if (opt) b[x]=y;	
			else a[x]=y;
		}
		else {
			R int l0=read(),r0=read(),l1=read(),r1=read();
			R int l=l0,r=r0;
			R int lim=r0-l0+1+r1-l1+1; lim>>=1;
			R bool flag=0;
			while (l<=r){
				R int mid=(l+r>>1);
				R pair<int,int> x=qa(l0,r0,a[mid]);
				R pair<int,int> y=qb(l1,r1,a[mid]);
				R int bigger=x.first+y.first;
				R int smaller=x.second+y.second;
				if (bigger<=lim && smaller<=lim){
					flag=1;
					out(a[mid]); putchar('\n');
					break;
				}
				if (bigger>lim) l=mid+1;
				else r=mid-1;
			}
			if (flag) continue;
			l=l1; r=r1;
			while (l<=r){
				R int mid=(l+r>>1);
				R pair<int,int> x=qa(l0,r0,b[mid]);
				R pair<int,int> y=qb(l1,r1,b[mid]);
				R int bigger=x.first+y.first;
				R int smaller=x.second+y.second;
				if (bigger<=lim && smaller<=lim){
					flag=1;
					out(b[mid]); putchar('\n');
					break;
				}
				if (bigger>lim) l=mid+1;
				else r=mid-1;
			}
		}
	}
	return 0;
}
