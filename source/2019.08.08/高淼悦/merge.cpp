#include<bits/stdc++.h>
using namespace std;

int F[500005];
int a[500005],b[500005];
vector <int> v;

int Find(int x)
{
	if (F[x]==x) return x;
	return F[x]=Find(F[x]);
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		F[i]=i;
		a[i]=1;
	}
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (x==1)
		{
			int t1=Find(x),t2=Find(y);
			F[t1]=t2;
			a[t2]+=a[t1];
		}
		else 
		{
			int t=Find(y);
			for (int j=1;j<=n;j++)
			{
				if (Find(j)==t) b[j]+=z;
			}
		}
	}
	cout<<b[1];
	for (int i=2;i<=n;i++) cout<<" "<<b[i]<<endl;
	return 0;
}


