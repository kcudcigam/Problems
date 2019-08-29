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

struct data{
	int x,y,z;
}b[260][260],a[260];
int g[10];
long long f[260][260];

bool cmp(data f1,data f2)
{
	if (f1.x!=f2.x) return f1.x<f2.x;
	else return f1.y<f2.y;
}

long long js(int x)
{
	long long t=1;
	long long s=0;
	for (int i=1;i<=5;i++)
	{
		t=t*x;
		s=s+g[i]*t;
	}
	return s;
}

long long work(int d1,int d2)
{
	if (a[d1].x>b[d1-1][d2].y||a[d2].y<b[d1-1][d2].x) return 0;
	return f[d1-1][d2]-js(b[d1-1][d2].z)+js(b[d1-1][d2].z+1);
}

int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	long long ans=0;
	n=read();
	m=read();
	for (int i=1;i<=5;i++) g[i]=read();
	for (int i=1;i<=n;i++)
	{
		a[i].x=read();
		a[i].y=read();
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			long long t1=f[i-1][j-1]+js(1);
			long long t2=work(i,j);
			if (t1>t2)
			{
				f[i][j]=t1;
				b[i][j].x=a[i].x;
				b[i][j].y=a[i].y;
				b[i][j].z=1;
			}
			else
			{
				f[i][j]=t2;
				b[i][j].x=max(a[i].x,b[i-1][j].x);
				b[i][j].y=min(a[i].y,b[i-1][j].y);
				b[i][j].z=b[i-1][j].z+1;
			}
			//cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<b[i][j].x<<" "<<b[i][j].y<<" "<<b[i][j].z<<endl;
			if (i==n) ans=max(ans,f[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}


