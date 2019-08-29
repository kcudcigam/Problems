#include<bits/stdc++.h>
using namespace std;
const int N=510000;
int a[N],b[N];
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
bool check(int l1,int r1,int l2,int r2,int t,int k){
	int x=lower_bound(a+l1,a+r1+1,t)-a-l1+lower_bound(b+l2,b+r2+1,t)-b-l2;
	int y=upper_bound(a+l1,a+r1+1,t)-a-l1+upper_bound(b+l2,b+r2+1,t)-b-l2;
	if(x<=k && y>k) return 1;
	return 0;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	while(m--){
		int ch=read();
		if(ch==1){
			int x=read(),y=read(),z=read();
			if(!x) a[y]=z;
			else b[y]=z;
		}
		else{
			int l1=read(),r1=read(),l2=read(),r2=read();
			int l=l1,r=r1,ans=r1,k=(r1-l1+r2-l2)/2+1;
			while(l<=r){
				int mid=(l+r)/2;
				int p=l2+k-(mid-l1)-1;
				if(p<=r2 && (p<l2 || a[mid]>=b[p])){
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(check(l1,r1,l2,r2,a[ans],k)){
				cout<<a[ans]<<"\n";
				continue;
			}
			l=l2,r=r2,ans=r2;
			while(l<=r){
				int mid=(l+r)/2;
				int p=l1+k-(mid-l2)-1;
				if(p<=r1 && (p<l1 || b[mid]>=a[p])){
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			if(check(l1,r1,l2,r2,b[ans],k))
				cout<<b[ans]<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}
