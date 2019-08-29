#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[100005];
int a[100005];
int b[100005];
int o;
inline int read()
{
	char c = getchar(); 
	int x = 0; 
	for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	b[i]=read();
	for(int i=1;i<=m;i++)
	{
		int typ=read();
		if(typ==1)
		{
			int x=read(),y=read(),z=read();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else 
		{
			int l1=read(),r1=read(),l2=read(),r2=read();
			o=0;
			for(int j=l1;j<=r1;j++)
			{
				ans[++o]=a[j];	
			}
			for(int j=l2;j<=r2;j++)
			{
				ans[++o]=b[j];
			}
			sort(ans+1,ans+1+o);
			printf("%d\n",ans[o/2+1]);
		}
	}
}
