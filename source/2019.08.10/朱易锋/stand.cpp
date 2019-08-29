#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const int N=300;
const int M=2000000+7; 
int lx[N],rx[N];
set<int>s[M];
set<int>::iterator it;
int tr[M],lazy[M<<2];
int n,m;
struct node
{
	int num,id;
};
I bool operator<(node a,node b)
{
	return a.num>b.num;
}
set<node>ans;
ll X[10];
bool v[N];
I ll pos(R int a,R int b)
{
	b--;
	while(b)
	{
		a*=a;
		b--;
	}
	return a;
}
I ll G(R int x)
{
	R ll ans=0;
	for(R int i=1;i<=5;i++)
	{
		if(!X[i])continue;
		ans+=(ll)X[i]*pow(x,i);
	}
	return ans;
}
I V insert(R int l,R int r,R int C)
{
	for(R int i=l;i<=r;i++)
	{
		tr[i]++;s[i].insert(C);
	}
}
V build(R int rt,R int l,R int r)
{
	if(l==r)
	{
		tr[l]=tr[l];
		lazy[rt]=0;
		return;
	}
	R int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
I V down(R int rt)
{
	if(lazy[rt]!=0)
	{
		lazy[ls]+=lazy[rt];
		lazy[rs]+=lazy[rt];
		lazy[rt]=0;
	}
}
V Insert(R int rt,R int l,R int r,R int LL,R int RR,R int C)
{
	if(LL<=l&&r<=RR)
	{
		lazy[rt]+=C;
		return;
	}
	R int mid=(l+r)>>1;
	if(LL<=mid)Insert(ls,l,mid,LL,RR,C);
	if(RR>mid)Insert(rs,mid+1,r,LL,RR,C);
}
V DOWN(R int rt,R int l,R int r)
{
	if(l==r)
	{
		tr[l]+=lazy[rt];
		lazy[rt]=0;
		return;
	}
	down(rt);
	R int mid=(l+r)>>1;
	DOWN(ls,l,mid);
	DOWN(rs,mid+1,r);
}
I V del(R int x)
{
	for(it=s[x].begin();it!=s[x].end();it++)
	{
		R int pos=*it;
		if(v[pos])continue;
		v[pos]=1;
		Insert(1,1,m,lx[pos],rx[pos],-1);
	}
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	memset(v,0,sizeof(v));
	scanf("%d%d",&n,&m);
	for(R int i=1;i<=5;i++)
	{
		scanf("%d",&X[i]);
	}
	for(R int i=1;i<=n;i++)
	{
		scanf("%d%d",&lx[i],&rx[i]);
		insert(lx[i],rx[i],i);
	}
	build(1,1,m);
	R int ret=0;
	R ll ANS=0;
	while(ret<n)
	{
		DOWN(1,1,m);
		ans.clear();
		for(R int i=1;i<=m;i++)
		{
			ans.insert((node){tr[i],i});
		}
		node now=*ans.begin();
		ANS+=G(now.num);
		ret+=now.num;
		del(now.id);
	}
	printf("%lld\n",ANS);
	return 0;
}
