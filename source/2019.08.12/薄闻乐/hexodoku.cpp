#include<bits/stdc++.h>
using namespace std;
int n,k,a[32],g,ans[32];
bool con(int l,int r,int x)
{
	if((l==x-6||l==x-5||l==x-1||l==x||l==x+1||l==x+5||l==x+6)&&(r==x-6||r==x-5||r==x-1||r==x||r==x+1||r==x+5||r==x+5||r==x+6))
	return 1;
	return 0;
}
bool check1(int x)
{
	for (int i=1;i<=31;i++)
	{
		for (int j=1;j<=31;j++)
		{
			if(con(i,j,x)&&ans[i]==ans[j])
			return 1;
		}
	}
	return 0;
}
bool check2(int x)
{
	int l,r;
	for (int i=1;i<=31;i++)
	{
	for (int j=1;j<=31;j++)
	{
		l=i;
		r=j;
		if((a[l]==a[r])&&(l==x-4||l==x-3||l==x-1||l==x||l==x+1||l==x+5||l==x+6)&&(r==x-4||r==x-3||r==x-1||r==x||r==x+1||r==x+5||r==x+5||r==x+6))
		return 1;
	}
	}
	return 0;
}
bool check3(int x)
{
	int l,r;
	for (int i=1;i<=31;i++)
	for (int j=1;j<=31;j++)
	{
		l=i;
		r=j;
		if((a[l]==a[r])&&(l==x-6||l==x-5||l==x-1||l==x||l==x+1||l==x+3||l==x+4)&&(r==x-6||r==x-5||r==x-1||r==x||r==x+1||r==x+5||r==x+3||r==x+4))
		return 1;
	}
	return 0;
}
bool check()
{
	for (int i=1;i<=31;i++)
	{
		if(a[i]==0)
		continue;
		if(a[i]!=ans[i])
		return 0;
	}
	for (int i=0;i<3;i++)
	{
		for (int j=1;j<=5;j++)
		{
			for (int k=j+1;k<=5;k++)
			{
				if(ans[i*11+2+j]==ans[i*11+2+k])
				return 0;
			}
		}
	}
	if(ans[1]==ans[4]||ans[1]==ans[9]||ans[1]==ans[14]||ans[1]==ans[19])
	return 0;
	for (int j=1;j<=4;j++)
	{
		for (int k=j+1;k<=4;k++)
		{
			if(ans[j*5-1]==ans[k*5-1])
			return 0;
		}
	}
	for (int j=1;j<=5;j++)
	{
		for (int k=j+1;k<=5;k++)
		{
			if(ans[j*5+1]==ans[k*5+1])
			return 0;
		}
	}
	for (int j=1;j<=4;j++)
	{
		for (int k=j+1;k<=4;k++)
		{
			if(ans[j*5+8]==ans[k*5+8])
			return 0;
		}
	}
	if(ans[31]==ans[13]||ans[31]==ans[18]||ans[31]==ans[23]||ans[31]==ans[28])
	return 0;
	for (int i=0;i<2;i++)
	{
		for (int j=1;j<=6;j++)
		{
			for (int k=j+1;k<=6;k++)
			{
				if(ans[i*2+j*6-5]==ans[i*2+k*6-5])
				return 0;
			}
		}
	}
	if(check2(5)||check1(9)||check1(12)||check1(16)||check1(20)||check1(23)||check3(27))
	return 0;
	return 1;
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&k,&n);
	for (int i=1;i<=31;i++)
	scanf("%d",&a[i]);
	if(k<=7&&n>1)
	{
		cout<<"No way"<<endl;
		return 0;
	}
	for (int i=1;i<=31;i++)
	ans[i]=1;
	if(n>k)
	{
		cout<<"No way"<<endl;
		return 0;
	}
	while(g<n)
	{
		next_permutation(1+ans,1+ans+31);
		for (int i=31;i>=1;i--)
		{
			if(ans[i]>n)
			{
				ans[i-1]++;
				ans[i]=1;
			}
			else break;
		}
		if(check())
		g++;
	}
	return 0;
}
