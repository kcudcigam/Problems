#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int a[1001][1001];
int c[500005],b[500005];
int MAX=1000000007;
int ans=0,n;

void work()
{	
	for (int i=1;i<n;i++)
	{
	 	for (int j=i+1;j<n;j++)
		{
			if (c[i]==0||c[j]==0) return;
			if (a[i][j]!=a[c[i]][c[j]]) return;
		}
	}
//	for (int i=1;i<=n;i++) cout<<c[i]<<" ";
//	cout<<endl;
	ans=(ans+1)%MAX;
}

int pd(int x,int y)
{
	for (int i=1;i<x;i++)
	{
//		if (c[1]==4) cout<<i<<" "<<x<<" "<<c[i]<<" "<<y<<" "<<a[i][x]<<" "<<a[c[i]][y]<<endl;
		if (a[i][x]!=a[c[i]][y]) return 0;
	}
	return 1;
}

void dg(int dep)
{
	if (dep>n) {work();return;}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (b[i]==0&&(dep==1||pd(dep,i)==1))
			{
				b[i]=1;
				c[dep]=i;
				dg(dep+1);
				b[i]=0;
			}
		}
	}
}

int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int Num,m1,m2;
	read(Num);read(n);read(m1);read(m2);
	long long f1=1,f2=1;
	for (int i=1;i<=m1;i++)
	{
		int x,y;
		read(x);read(y);
		a[x][y]=1;
		a[y][x]=1;
		f1=(long long)f1*i%MAX*2%MAX;
	}
	for (int i=1;i<=m2;i++)
	{
		int x,y;
		read(x);read(y);
		a[x][y]=2;
		a[y][x]=2;
		f2=(long long)f2*i%MAX*2%MAX;
	}
	f1=f1*f2%MAX;
	long long h=1;
	for (int i=1;i<=n;i++)
	{
		h=(long long)h*i%MAX;
	}
	if (Num>=7&&Num<=14) 
	{
		cout<<(h+MAX-f1)%MAX<<endl;
		return 0;
	}
	dg(1);
	h=(h+MAX-ans)%MAX;
	cout<<h<<endl;
	return 0;
}

