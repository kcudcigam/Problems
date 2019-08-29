#include<bits/stdc++.h>
using namespace std;
#define RG register
#define M 500100
#define int long long 
inline int rred()
{
	int s=0;char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
int n,m,ans1;
int a[M],b[M];
signed main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=rred(),m=rred();
	for(RG int i=1;i<=n;i++)	a[i]=rred();
	for(RG int i=1;i<=n;i++)	b[i]=rred();
		for(RG int i=1;i<=m;i++)
	{
		int x=rred();
		if(x==1)
		{
			x=rred();
			int y=rred(),z=rred();
			if(x) b[y]=z;
			else  a[y]=z;
		}
		else
		{
			int l=rred(),r=rred(),ll=rred(),rr=rred();
			x=l;int xx=ll,y=r,yy=rr;
			int cnt=(r-l+rr-ll+2)>>1;
			//------
			l=x,ll=xx,r=y,rr=yy;
			while(l<r)
			{
				int mid=(l+r)>>1;
				while(ll<rr)
				{
					int midd=(ll+rr)>>1;
					if(a[mid]>=b[midd]) ll=midd+1;
					else rr=midd;
				}
				if((mid-x+ll-xx)<=cnt) l=mid+1;
				else r=mid;
			}
			ans1=l;
			ll=xx,rr=yy;
				while(ll<rr)
				{
					int midd=(ll+rr)>>1;
					if(a[ans1]>=b[midd]) ll=midd+1;
					else rr=midd;
				}
			if((ans1-x+ll-xx)==cnt)
			{
				cout<<a[ans1]<<endl;
				continue;
			}
			else
			{
					ans1=l-1;
			ll=xx,rr=yy;
				while(ll<rr)
				{
					int midd=(ll+rr)>>1;
					if(a[ans1]>=b[midd]) ll=midd+1;
					else rr=midd;
				}
			 if((ans1-x+ll-xx)==cnt)
			 {
				cout<<a[ans1]<<endl;
				continue;
			 }
			}
			//------------
			l=x,ll=xx,r=y,rr=yy;
			while(ll<rr)
			{
				int midd=(ll+rr)>>1;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(b[midd]>=a[mid]) l=mid+1;
					else r=mid;
				}
				if((midd-xx+l-x)<=cnt) ll=midd+1;
				else rr=midd;
			}
			ans1=ll;
			l=x,r=y;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(b[ans1]>=a[mid]) l=mid+1;
					else r=mid;
				}
			if((ans1-xx+l-x)==cnt) cout<<b[ans1]<<endl;
			else cout<<b[ans1-1]<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
