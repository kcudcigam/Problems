#include<bits/stdc++.h>
using namespace std;

const int maxn=300000+5;
int ans[maxn],add[maxn],sum;

struct node
{
	int x,y;
};node mp[maxn];
bool cmp(const node &a,const node &b)
{
	return a.x<b.x;
}

void build(int a,int b)
{
	sum++;mp[sum].x=a;mp[sum].y=b;
	add[a]++;
}

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
    int n,m,q,a,b;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) 
    {
    	cin>>a>>b;
    	build(a,b);
    	build(b,a);
	}
	sort(mp+1,mp+sum+1,cmp);
	for(int i=1;i<=n;i++) add[i]+=add[i-1];
	int flag,d,w;
	while(q--)
	{
		cin>>flag>>d;
		if(flag==0){cout<<ans[d]<<endl;}
		else 
		{
			cin>>w;
			for(int i=add[d-1];i<=add[d];i++)
			   ans[mp[i].y]+=w;
		}
	}
	return 0;
}
