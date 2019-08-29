#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
   int f=1;x=0;char c=getchar();
   for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
   for (; isdigit(c);c=getchar()) x=x*10+c-'0';
   x*=f;
}  
int a[500005],b[500005],c[500004],d[500004];
int main() 
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m,i,j;
	read(n);
	read(m);
	for (i=1;i<=n;i++)
	  read(a[i]);
	for (i=1;i<=n;i++)
	  read(b[i]);
    if (n<=1000&&m<=2000)
	{
	  	for (i=1;i<=m;i++)
	{
		int f,x,y,z,l1,l2,r2,r1,l,r,midi;
		read(f);
		if (f==1) {
			read(x);
			read(y);
			read(z);
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		if (f==2)
		{
			memset(d,0,sizeof(d));
			int t=0;
			read(l1);
			read(r1);
			read(l2);
			read(r2);
			for (j=l1;j<=r1;j++) {t++;d[t]=a[j];}	
			for (j=l2;j<=r2;j++) {t++;d[t]=b[j];}	
			sort(d+1,d+t+1);
			cout<<d[(1+t)/2]<<endl;
		}
	 }
	 return 0; 
	}
	for (i=1;i<=m;i++)
	{
		int f,x,y,z,l1,l2,r2,r1,l,r,midi;
		read(f);
		if (f==1) {
			read(x);
			read(y);
			read(z);
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		if (f==2)
		{
			read(l1);
			read(r1);
			read(l2);
			read(r2);
			l=1;
			r=1000000001;
		    while (l<r)
			{
				midi=(l+r+1)/2;
				int aa1=lower_bound(a+1,a+n+1,midi)-a;
				int bb1=lower_bound(b+1,b+n+1,midi)-b;
				if (aa1-l1+bb1-l2<=(r1-l1+r2-l2+1)/2) l=midi;
				else r=midi-1;
			}
			cout<<(l+r+1)/2<<endl;	
		}
	}
	return 0;
}
