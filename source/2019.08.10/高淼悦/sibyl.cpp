#include<bits/stdc++.h>
using namespace std;

int read()
{
	char ch=getchar();
	int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+(ch-'0');ch=getchar();}
	return n*f;
}

int n,m,q;
vector <int> v[300005];
int b[300005];
int d[300005];

void work1()
{
	int a[300005];
	memset(a,0,sizeof(a));
	for (int i=1;i<=q;i++)
	{
		int t,x,y;
		t=read();
		if (t==1)
		{
			x=read();
			y=read();
			a[x]+=y;
			for (int i=0;i<v[x].size();i++)
			{
				a[v[x][i]]+=y;
			}
		}
		else
		{
			x=read();
			cout<<a[x]<<endl;
		}
	}
}

int pd1()
{
	int f=1;
	for (int i=2;i<=n;i++) 
	{
		if (v[i].size()>10)  return 0;
	}
	return 1;
}

void work2()
{
	int a[300005];
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	for (int i=1;i<=q;i++)
	{
		//cout<<"%%"<<endl;
		int t,x,y;
		t=read();
		if (t==1)
		{
			x=read();
			y=read();
			a[x]+=y;
			d[x]+=y;
			if (x==1) continue;
			for (int i=0;i<v[x].size();i++)
			{
				a[v[x][i]]+=y;
			}
		}
		else
		{
			x=read();
			int ans=a[x];
			if (b[x]==1) ans=a[x]+d[1];
			cout<<ans<<endl;
		}
	}
}

void work3()
{
	int a[300005];
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	for (int i=1;i<=q;i++)
	{
		int t,x,y;
		t=read();
		if (t==1)
		{
			x=read();
			y=read();
			a[x]+=y;
			d[x]+=y;
			if (v[x].size()>1||v[x].size()==0) continue;
			a[v[x][0]]+=y;
		}
		else
		{
			x=read();
			if (v[x].size()==1) a[x]+=d[v[x][0]];
			cout<<a[x]<<endl; 
		}
	}
}

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();
	m=read();
	q=read();
	for (int i=1;i<=m;i++)
	{
		int x,y;
		x=read();
		y=read();
		v[x].push_back(y);
		v[y].push_back(x);
		if (x==1) b[y]=1;
		if (y==1) b[x]=1;
	}
	if (n<=3000&&m<=3000&&q<=3000) work1();
	else if (pd1()==1) work2();
	     else 
		 work3();
	return 0;
}


