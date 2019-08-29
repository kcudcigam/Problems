#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
typedef long long ll;
const int N=200010;
int n,A,B,C,D,maxi,a[N];
ll maxn=-INF,ans[N],f[N];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		ans[rt]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);build(mid+1,r,rt<<1|1);
	ans[rt]=min(ans[rt<<1],ans[rt<<1|1]);
}
int search(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R)return ans[rt];
	int mid=(l+r)>>1;
	int Ans=INF;
	if(L<=mid)Ans=min(Ans,search(L,R,l,mid,rt<<1));
	if(R>mid)Ans=min(Ans,search(L,R,mid+1,r,rt<<1|1));
	return Ans;	
}
ll solve(int t)
{
	return A*t*t*t+B*t*t+C*t+D;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(ans,INF,sizeof(ans));
	memset(f,-0x3f3f3f3f,sizeof(f));
	build(1,n,1);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(f[i]<f[j]+solve(search(j+1,i,1,n,1)))
				f[i]=f[j]+solve(search(j+1,i,1,n,1));
		}
	}
	cout<<f[n];
	return 0;
}

