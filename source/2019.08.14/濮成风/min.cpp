#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=2E5+5;
const ll inf=1E14;
int n;
ll A,B,C,D,a[maxn],f[maxn],q[maxn];
inline ll min(ll x,ll y)
{
	return x<y?x:y;
}
inline ll max(ll x,ll y)
{
	return x>y?x:y;
}
inline ll get(ll x)
{
	return A*x*x*x+B*x*x+C*x+D;
}
struct segment
{
	ll maxF[maxn*4],ans[maxn*4];
	void build(int l,int r,int num)
	{
		ans[num]=maxF[num]=-inf;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(l,mid,num<<1),build(mid+1,r,num<<1|1);
	}
	void insert(int l,int r,int pos,int num,ll x)
	{
		if(l==r)
		{
			ans[num]=maxF[num]=x;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
			insert(l,mid,pos,num<<1,x);
		else
			insert(mid+1,r,pos,num<<1|1,x);
		maxF[num]=max(maxF[num<<1],maxF[num<<1|1]);
	}
	void change(int L,int R,int l,int r,int num,ll x)
	{
		if(L<=l&&r<=R)
		{
			ans[num]=maxF[num]+x;
			return;
		}
		int mid=(l+r)>>1;
		if(R<=mid)
			change(L,R,l,mid,num<<1,x);
		else if(mid<L)
			change(L,R,mid+1,r,num<<1|1,x);
		else
			change(L,R,l,mid,num<<1,x),change(L,R,mid+1,r,num<<1|1,x);
		ans[num]=max(ans[num<<1],ans[num<<1|1]);
	}
}T;
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	T.build(1,n,1);
	int top=0;
	for(int i=1;i<=n;++i)
	{
		while(top&&a[i]<=a[q[top]])
			--top;
		T.insert(1,n,i,1,f[i-1]);
		T.change(q[top]+1,i,1,n,1,get(a[i]));
		q[++top]=i;
		f[i]=T.ans[1];
	}
	cout<<f[n]<<endl;
	return 0;
}

