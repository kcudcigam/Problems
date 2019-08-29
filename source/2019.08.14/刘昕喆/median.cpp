#include<bits/stdc++.h>
using namespace std;
int R()
{
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m;
int a[500001][2];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=R();m=R();
	for(int i=1;i<=n;i++)
	{
		a[i][0]=R();
	}
	for(int i=1;i<=n;i++)
	{
		a[i][1]=R();
	}
	for(int i=1;i<=m;i++)
	{
		int op;
		op=R();
		if(op==1)
		{
			int x,y,z;
			x=R();y=R();z=R();
			a[y][x]=z;
		}
		if(op==2)
		{
			int l1,r1,l2,r2;
			l1=R();r1=R();l2=R();r2=R();
			int len=((r1+r2-l1-l2+2)>>1)+1,t1=l1,t2=l2,ans=0;
			for(int i=1;i<=len;i++)
			{
				if((a[t1][0]>a[t2][1] && t2<=r2)||t1>r1)
				{
					ans=a[t2][1];
					t2++;
				}
				else
				{
					ans=a[t1][0];
					t1++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

