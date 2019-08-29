#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000],b[10000];
void work1(int x,int y)
{
for (int i=1;i<=n;i++)
	{
		if (b[i]==b[y]) b[i]=b[x];
	}
	
}
void work2(int x,int y)
{
	for (int i=1;i<=n;i++)
	{
		if (b[i]==b[x]) a[i]+=y;
	}
	
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	b[i]=i;
	for (int i=1;i<=m;i++)
	{
		int c,x,y;
		cin>>c>>x>>y;
		if (c==1) work1(x,y);
		if (c==2) work2(x,y);
	}
	for (int i=1;i<=n-1;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<a[n]<<endl;
	return 0;
}


