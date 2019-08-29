#include<bits/stdc++.h>
using namespace std;
int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return f*n;
}

int Low[200005],La[200],st[200005][30];
int b[10],a[200005];
int h[200005];
long long f[505][505];

int js(int l,int r)
{
	int f=Low[r-l+1];
	if (La[f]==r-l+1) return st[l][f];
	int ans=min(st[l][f],st[r-La[f]+1][f]);
//	cout<<"   "<<l<<" "<<r<<" "<<f<<" "<<st[l][f]<<" "<<st[r-La[f]+1][f]<<endl; 
	return ans;
}

long long pd(int x)
{
	long long ans=0,N=1;
	for (int i=4;i>=1;i--)
	{
		ans=ans+N*b[i];
		N=N*x;
	}
	return ans;
}

int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=4;i++) cin>>b[i];
	for (int i=1;i<=n;i++) cin>>a[i];
	Low[1]=0;
	for (int i=2;i<=n;i++) Low[i]=Low[i>>1]+1;
	La[0]=1;
	for (int i=1;i<=Low[n];i++) 
	{
		La[i]=1<<i;
	//	cout<<i<<" "<<La[i]<<endl;
	}
	for (int i=1;i<=n;i++) st[i][0]=a[i];
	for (int j=1;j<=Low[n];j++)
	{
		for (int i=1;i<n;i++)
		{
			st[i][j]=min(st[i][j-1],st[i+La[j-1]][j-1]);
		//	cout<<"&& "<<i<<" "<<j<<" "<<st[i][j]<<" "<<st[i][j-1]<<" "<<i+La[j-1]<<endl;
		}
	}
	if (n<=400)
	{
		for (int i=1;i<=n;i++) f[i][i]=pd(a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i;j++)
		{
			f[i][i+j]=pd(js(i,i+j));
		//	cout<<"!!  "<<i<<" "<<i+j<<" "<<f[i][j]<<endl;
			for (int k=i;k<i+j;k++)
			{
				f[i][i+j]=max(f[i][k]+f[k+1][i+j],f[i][j]);
			//	cout<<k<<" "<<f[i][k]<<" "<<f[k+1][i+j]<<endl;
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
	}
	int l=1;
	long long ans=pd(js(1,n));
	long long p=0,k=0;
	for (int i=1;i<n;i++)
	{
		int x=pd(js(1,i)),y=pd(js(i+1,n));
		if (x+y>ans) h[i]=1;
	}
	l=0;
	ans=0;
	for (int i=1;i<n;i++)
	{
		if (h[i]==1)
		{
			ans+=pd(js(l+1,i));
			l=i;
		}
	}
	ans+=pd(js(l+1,n));
//	p=p+k;
	cout<<ans<<endl;
	return 0;
}

