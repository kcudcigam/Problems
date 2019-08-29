#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[500010];
template <typename T> void read(T &p){
int f=1;p=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) p=p*10+c-'0';
p*=f;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for (long long i=1;i<=n;i++) read(a[i]);
	for (long long i=1;i<=n;i++) read(b[i]);
	for (long long i=1;i<=m;i++){
		long long t;
		read(t);
		if (t==1){
			long long x,y,z;
			read(x);read(y);read(z);
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		else{
			long long l1,r1,l2,r2,ans;
			read(l1);read(r1);read(l2);read(r2);
			ans=(r1-l1+1+r2-l2+1)/2;
				
			long long l=l1,r=r1;
			long long mi;
			bool flag=false;
			while(l<=r){
				mi=(l+r)/2;
				if ((b[ans-mi+l1+l2-1]<=a[mi])&&(b[ans-mi+l1+l2]>=a[mi])){
					flag=true;
				//	cout<<ans-mi+l1+l2-1<<" "<<mi<<" "<<l1<<" "<<l2<<" "<<ans<<endl; 
					break;
				}
				else{
					if ((b[ans-mi+l1+l2-1]>a[mi])) l=mi+1;
					else r=mi;
				}
				if ((mi==l)&&(mi==r)) break;
			}
//			cout<<"shidfst"<<endl;
			if (flag==true) cout<<a[mi]<<endl; 
			else{
				long long l=l2,r=r2;
				long long mi;
				bool flag=false;
				while(l<=r){
					mi=(l+r)/2;
					if ((a[ans-mi+l2+l1-1]<=b[mi])&&(a[ans-mi+l2+l1]>=b[mi])){
						flag=true;
						break;
					}
					else{
						if ((a[ans-mi+l2+l1-1]>b[mi])) l=mi+1;
						else r=mi;
					}
					if ((mi==l)&&(mi==r)) break;
				}
				if (flag==true) cout<<b[mi]<<endl;
			}
			
		}
	}
	return 0;
}


