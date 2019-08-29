#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
int n,m,op,x,y,z;
int ai[500010],bi[500010],l1,r1,l2,r2;
int mid_search()
{
	int l=l1,r=r1,ans=0;
	int leni=(r1-l1+1)+(r2-l2+1),med=(leni+1)/2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int ll=lower_bound(bi+l2,bi+r2+1,ai[mid])-bi;
		if(bi[ll]>ai[mid]||ll==r2+1)
		{
			if((mid-l1+1)+(ll-l2)==med) {ans=mid;break;}
			else if((mid-l1+1)+(ll-l2)<med) l=mid+1;
			else r=mid-1;
		}
		else
		{
			int rr=upper_bound(bi+l2,bi+r2,ai[mid])-bi-1;
			if((mid-l1)+(ll-l2+1)<=med&&(mid-l1+1)+(rr-l2+1)>=med) {ans=mid;break;}
			else if((mid-l1)+(ll-l2+1)>med) r=mid-1;
			else l=mid+1;
		}
	}
	if(ans) return ai[ans];
	l=l2,r=r2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int ll=lower_bound(ai+l1,ai+r1+1,bi[mid])-ai;
		if(ai[ll]>bi[mid]||ll==r1+1)
		{
			if((mid-l2+1)+(ll-l1)==med) {ans=mid;break;}
			else if((mid-l2+1)+(ll-l1)<med) l=mid+1;
			else r=mid-1;
		}
		else
		{
			int rr=upper_bound(ai+l1,ai+r1,bi[mid])-ai-1;
			if((mid-l2)+(ll-l1+1)<=med&&(mid-l2+1)+(rr-l1+1)>=med) {ans=mid;break;}
			else if((mid-l2)+(ll-l1+1)>med) r=mid-1;
			else l=mid+1;
		}
	}
	return bi[ans];
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(ai[i]);
	for(int i=1;i<=n;i++) read(bi[i]);
	for(int i=1;i<=m;i++)
	{
		read(op);
		if(op==1)
		{
			read(x),read(y),read(z);
			if(!x) ai[y]=z; else bi[y]=z;
		}
		else
		{
			read(l1),read(r1),read(l2),read(r2);
			printf("%d\n",mid_search());
		}
	}
	return 0;
}

