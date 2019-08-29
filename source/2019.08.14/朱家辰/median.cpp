#include<bits/stdc++.h>
#define maxn 500010
#define inf 0x3f3f3f3f
using namespace std;
int a[2][maxn];
int pos[2][maxn];
int n,m;
void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int ef(int x,int k)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(k==0)
		{
			if(a[k][mid]<=x) l=mid+1;
			else r=mid;
		}
		else
		{
			if(a[k][mid]<x) l=mid+1;
			else r=mid;
		}
	}
	return l-1;
}
int getans(int s,int l1,int r1,int l2,int r2,int k)
{
	int l=l1,r=r1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(mid-l1+max(pos[k][mid]-l2+1,0)<s) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	fread(n),fread(m);
	for(int i=1;i<=n;i++) fread(a[0][i]);
	for(int i=1;i<=n;i++) fread(a[1][i]);
	for(int i=1,j=1;i<=n||j<=n;)
	{
		if((a[0][i]<=a[1][j]||j>n)&&i<=n) 
		{
			pos[0][i]=j-1;
			i++;
		}
		else
		{
			pos[1][j]=i-1;
			j++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		fread(op);
		if(op==1)
		{
			int x,y,z;
			fread(x),fread(y),fread(z);
			a[x][y]=z;
			pos[x][y]=ef(z,x^1);
		}
		else
		{
			int l1,r1,l2,r2,p1,p2,s;
			fread(l1),fread(r1),fread(l2),fread(r2);
			s=(r1-l1+r2-l2+2)/2;
			p1=getans(s,l1,r1,l2,r2,0);
			p2=getans(s,l2,r2,l1,r1,1);
			if(p1-l1+max(pos[0][p1]-l2+1,0)==s) printf("%d\n",a[0][p1]);
			else printf("%d\n",a[1][p2]);
		}
	}
	return 0;
}

