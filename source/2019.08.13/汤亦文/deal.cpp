#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp 1000000007
inline int read()
{
	int s=0;char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0') s=s*10+c-'0',c=getchar();
	return s;
}
int n,m;
int f[10100];
int ff[10100];
int q[10100];
int v[1050],w[1050],c[1050],cc[1050];
inline int calc(int i,int u,int k){return f[u+k*v[i]];}
inline int calcf(int i,int u,int k){return ff[u+k*v[i]];}
signed main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read(),m=read();
	int Y=0;
	for(int i=1;i<=n;i++)
	{
		w[i]=read(),c[i]=read(),cc[i]=read();
		v[n-i+1]=v[i];
		if(!c[i]) Y=w[i];
	}
	int x=m;
	Y=Y+x-1;
	f[0]=1;
	int mm=m;
	m=Y;
	for(int i=1;i<=n;i++)
	{
		for(int u=0;u<v[i];u++)
		{
			int l=1,r=0;
			int maxp=(m-u)/v[i];
			int qpq=0;
			for(int k=maxp-1;k>=max(maxp-c[i],qpq);k--)
			{
				while(l<=r&&calc(i,u,q[r])<=calc(i,u,k)) r--;
				q[++r]=k;
			}
			for(int p=maxp;p>=0;p--)
			{
				while(l<=r&&(q[l]>(p-1))) l++;
				if(l<=r&&(u+p*v[i]-x)<v[i]) f[u+p*v[i]]=(calc(i,u,q[l])+f[u+p*v[i]])%mp;
				if(p-c[i]-1>=0)
				{
					while(l<=r&&calc(i,u,q[r])<=calc(i,u,p-c[i]-1)) r--;
					q[++r]=p-c[i]-1;
				}
			}
		}
	}
//---------------------------------------------------------------------------------
    m=x-1;
    ff[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int u=0;u<w[i];u++)
		{
			int l=1,r=0;
			int maxp=(m-u)/w[i];
			int pqp=0;
			for(int k=maxp-1;k>=max(maxp-c[i],pqp);k--)
			{
				while(l<=r&&calcf(i,u,q[r])<=calcf(i,u,k)) r--;
				q[++r]=k;
			}
			for(int p=maxp;p>=0;p--)
			{
				while(l<=r&&(q[l]>(p-1))) l++;
				if(l<=r) ff[u+p*v[i]]=(calcf(i,u,q[l])+ff[u+p*v[i]])%mp;
				if(p-c[i]-1>=0)
				{
					while(l<=r&&calcf(i,u,q[r])<=calcf(i,u,p-c[i]-1)) r--;
					q[++r]=p-c[i]-1;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
	ans+=(ff[i]*f[i+x]+ans)%mp;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
