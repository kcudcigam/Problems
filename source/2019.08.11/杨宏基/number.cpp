#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long excel[1000001],box[101];
long long n;
int t,T;
void dfs(int k,int l,int u,int v)
{
	if(k>l)
	{
		if(box[1]==0)
			return;
		t++;
		long long h=box[1];
		for(int i=2;i<=l;i++)
			h=h*10+box[i];
		excel[t]=h;
		return;
	}
	box[k]=u;
	dfs(k+1,l,u,v);
	box[k]=v;
	dfs(k+1,l,u,v);
}
bool srch(long long x)
{
	int l=1,r=t,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(excel[mid]<x)
			l=mid+1;
		else
			r=mid;
	}
	if(x==excel[l])
		return true;
	else
		return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=99;i++)
		excel[i]=i;
	t=99;
	for(int i=3;i<=13;i++)
		for(int u=0;u<=9;u++)
			for(int v=u+1;v<=9;v++)
				dfs(1,i,u,v);
	excel[++t]=1e13;
	sort(excel+1,excel+1+t);
	int c=0;
	for(int i=1;i<=t;i++)
		if(excel[i]!=excel[c])
			excel[++c]=excel[i];
	t=c;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(srch(n))
			printf("1\n");
		else
		{
			c=0;
			for(int i=1;i<=t&&excel[i]<n;i++)
				if(srch(n-excel[i]))
				{
					c=1;
					break;
				}
			if(c)
				printf("2\n");
			else
				printf("3\n");
		}
	}
}
