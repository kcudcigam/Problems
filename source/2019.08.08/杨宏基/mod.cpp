#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int box[10001],c[10001],v[10001];
int w,s,n,p;
void dfs(int k)
{
	if(k>n)
	{
		w=0;
		for(int i=1;i<=n;i++)
		{
			w+=(box[i]!=c[i]);
			c[i]=box[i];
		}
		s+=w;
		return;
	}
	for(int i=n;i>=1;i--)
		if(!v[i])
		{
			v[i]=1;
			box[k]=i;
			dfs(k+1);
			v[i]=0;
		}
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int m;
	cin>>m;
	while(m--)
	{
		cin>>n>>p;
		s=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
			c[i]=n-i+1;
		dfs(1);
		cout<<s%p<<endl;
	}
}
