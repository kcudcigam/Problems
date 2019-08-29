#include<cstdio>
#include<iostream>
using namespace std;
int dad[1000001],cnt[1000001];
int n,q;
int find(int x)
{
	if(x==dad[x])
		return x;
	return dad[x]=find(dad[x]);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		dad[i]=i;
	while(q--)
	{
		int o,x,y;
		cin>>o>>x>>y;
		if(o==1)
			dad[find(x)]=find(y);
		if(o==2)
		{
			int c=find(x);
			for(int i=1;i<=n;i++)
				if(c==find(i))
					cnt[i]+=y;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<' ';
}
