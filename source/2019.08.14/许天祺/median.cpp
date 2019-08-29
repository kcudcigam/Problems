#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
int n,m,a[500005],b[500005],opt,x,y,z,l1,r1,l2,r2;
signed main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if (opt==1)
		{
			x=read();
			y=read();
			z=read();
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		if (opt==2)
		{
			l1=read();
			r1=read();
			l2=read();
			r2=read();
			int l=0,r=INT_MAX,mid;
			while(l<r)
			{
				mid=(l+r+1)/2;
//				cout<<l<<" "<<r<<" "<<mid<<endl;
				int aa1=lower_bound(a+1,a+n+1,mid)-a;
				int bb1=lower_bound(b+1,b+n+1,mid)-b;
//				cout<<aa1<<" "<<bb1<<" "<<mid<<endl;
				if (aa1<l1) aa1=l1;
				if (aa1>r1) aa1=r1+1;
				if (bb1<l2) bb1=l2;
				if (bb1>r2) bb1=r2+1;
				if (aa1-l1+bb1-l2<=(r1-l1+r2-l2+1)/2) l=mid;
				else r=mid-1;
			}
			cout<<(l+r+1)/2<<endl;
		}
	}
	return 0;
}
