#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
long long ai[500010];
struct Seg{
	long long tag,val;
}xds[2001000];
void push_up(int pos)
{
	xds[pos].val=xds[pos<<1].val+xds[pos<<1|1].val;
}
void Add(int pos,int l,int r,int k)
{
	xds[pos].tag+=k;
	xds[pos].val+=(r-l+1)*k;
}
void push_down(int pos,int l,int r)
{
	if(xds[pos].tag==0) return;
	int mid=(l+r)>>1;
	Add(pos<<1,l,mid,xds[pos].tag);
	Add(pos<<1|1,mid+1,r,xds[pos].tag);
	xds[pos].tag=0;
}
void build(int pos,int l,int r)
{
	if(l==r)
	{
		xds[pos].val=ai[l];
		return;
	}
	int mid=(l+r)>>1;
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	push_up(pos);
}
void modify(int pos,int l,int r,int ll,int rr,int k)
{
	if(l>=ll&&r<=rr)
	{
		Add(pos,l,r,k);
		return;
	}
	push_down(pos,l,r);
	int mid=(l+r)>>1;
	if(mid>=ll) modify(pos<<1,l,mid,ll,rr,k);
	if(mid<rr) modify(pos<<1|1,mid+1,r,ll,rr,k);
	push_up(pos);
}
void Get_ans(int pos,int l,int r)
{
	if(l==r)
	{
		ai[l]=xds[pos].val;
		return;
	}
	push_down(pos,l,r);
	int mid=(l+r)>>1;
	Get_ans(pos<<1,l,mid);
	Get_ans(pos<<1|1,mid+1,r);
	push_up(pos);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,l,r;
	long long s,e;
	read(n),read(m);
	//for(int i=1;i<=n;i++)
		//read(ai[i]),ai[i]-=ai[i-1];
	//build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		read(l),read(r),read(s),read(e);
		modify(1,1,n,l,l,s);
		if(l!=r)
			modify(1,1,n,l+1,r,(e-s)/(r-l));
		if(r!=n)
			modify(1,1,n,r+1,r+1,-e);
	}
	Get_ans(1,1,n);
	long long ans=ai[1];
	for(int i=2;i<=n;i++)
		ai[i]+=ai[i-1],ans^=ai[i];//,cout<<ai[i]<<endl;
	cout<<ans<<endl;
	return 0;
}

