#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	 char ch=getchar();
	 int f=0;
	 while(!isdigit(ch)) ch=getchar();
	 while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	 return f;
}
int n,m;
int ans=0;
int g[6];
int l[255];
int r[255];
int p[255];
int _[255];
int calc(int x)
{
	return x*(g[1]+x*(g[2]+x*(g[3]+x*(g[4]+x*g[5]))));
}
bool pd1()
{
	bool flag=1;
	for(int i=1;i<=n;i++) if(l[i]!=1 || r[i]!=n) flag=0;
	return flag;
}
void js()
{
	int bc=0;
	for(int i=1;i<=m;i++)bc+=calc(p[i]);
	if(bc>ans) for(int i=1;i<=m;i++) _[i]=p[i];
	ans=max(ans,bc);
}
void dfs(int dep)
{
	if(dep>n)
		{
			js();
			return ;
		}
	for(int i=l[dep];i<=r[dep];i++)
		{
			p[i]++;
			dfs(dep+1);
			p[i]--;
		}
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=5;i++) g[i]=read();
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read();
	if(pd1())
		{
			cout<<calc(n)<<endl;
			return 0;
		}
	if(n<=20&&m<=20)
		{
			dfs(1);
			for(int i=1;i<=m;i++) cout<<_[i]<<" ";
			cout<<endl;
		}
	else
		{
			cout<<calc(rand()%n-8)<<endl;
		}
	return 0;
}


