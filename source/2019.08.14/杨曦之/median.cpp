#include<bits/stdc++.h>
using namespace std;
int const maxn=500000+10;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int a[maxn],b[maxn],n,m,st;
bool jud1(int pos,int rr,int s,int t){
	int x,p,i;
	x=a[pos];
	p=lower_bound(b+s,b+t,x)-b;
	if(x==b[p]) p++;
	p=p-s;
	p+=rr;
	if(p>=st) return false;
	else return true;
}
bool jud2(int pos,int rr,int s,int t){
	int x,p,i;
	x=b[pos];
	p=lower_bound(a+s,a+t,x)-a;
	if(x==a[p]) p++;
	p=p-s;
	p+=rr;
	if(p>=st) return false;
	else return true;
}
bool Fjud(int pos,int rr,int s,int t){
	int lo,hi,x;
	x=a[pos];
	lo=lower_bound(b+s,b+t,x)-b;
	hi=upper_bound(b+s,b+t,x)-b;
	if(b[lo]!=x) lo--;
	if(b[hi]!=x) hi--;
	lo=lo-s+1;hi=hi-s+1;
	lo+=rr;hi+=rr;
	if(st>=lo&&st<=hi) return true;
	else return false;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();m=ri();
	int i,j,op,x,y,z,l1,l2,r1,r2,ra;
	int l,r,mid;
	for(i=1;i<=n;++i) a[i]=ri();
	for(i=1;i<=n;++i) b[i]=ri();
	while(m--){
		op=ri();
		if(op==1){
			x=ri();y=ri();z=ri();
			if(x)b[y]=z;
			else a[y]=z;
		}
		else{
			l1=ri();r1=ri();l2=ri();r2=ri();
			l=l1;r=r1;
			st=(r1-l1+1+r2-l2+1)>>1;st++;
			while(l<r){
				mid=(l+r)>>1;ra=mid-l1+1;
				if(jud1(mid,ra,l2,r2)) l=mid+1;
				else r=mid;
				
			}
			ra=l-l1+1;
			if(Fjud(l,ra,l2,r2)) printf("%d\n",a[l]);
			else{
				l=l1;r=r1;
				while(l<r){
					mid=(l+r)>>1;ra=mid-l2+1;
					if(jud2(mid,ra,l1,r1)) l=mid+1;
					else r=mid;
				}
				printf("%d\n",b[l]);
			}
		}
	}
	return 0;
}

