#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
template <typename T> inline void print(T x){
	write(x); putchar(' ');
}
int a[500010],b[500010];
int n,m,x,y,z,l1,r1,l2,r2,k,opt,ans;
int main(){
	fre("median")
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	while (m--){
		read(opt);
		if (opt==1){
			read(x); read(y); read(z);
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		if (opt==2){
			read(l1); read(r1); read(l2); read(r2);
			int k=r1-l1+r2-l2+2;
			k=(k+1)/2;
			if (r1-l1>r2-l2){
				int p;
				int q=l1;
				ans=-1;
				while ((p=lower_bound(a+l1,a+q+k,b[l2])-a)!=q+k&&l2<=r2){
//					cout<<p<<endl;
					if (p==l1+k-1){
						ans=b[l2];
						break;
					}
					k--; 
					l2++;
				}
				if (ans==-1) ans=a[q+k-1];
				writeln(ans);
			}else{
				int p;
				ans=-1;
				int q=l2;
				while ((p=lower_bound(b+l2,b+q+k,a[l1])-b)!=q+k&&l1<=r1){
//					cout<<p<<endl;
					if (p==l2+k-1){
						ans=a[l1];
						break;
					}
					k--;
					l1++;
				}
				if (ans==-1) ans=b[q+k-1];
				writeln(ans);
			}
		}
	}
	return 0;
}

