#include<bits/stdc++.h>
using namespace std;
int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return f*n;
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n,m,q,m1=INT_MAX,m2=INT_MIN;
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		m2=max(x,m2);
		m1=min(x,m1);
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	cout<<m1+m2<<endl;
	return 0;
}

