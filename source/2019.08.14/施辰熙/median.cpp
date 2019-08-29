#include<bits/stdc++.h>
using namespace std;
inline int read() 
{
	char c = getchar(); 
	int x = 0; 
	for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) 
	x = x * 10 - '0' + c; 
	return x;
}
const int MAXN=500010;
long long n,m,opt,x,y,z,l1,l2,r1,r2;
long long a[3][MAXN],bound,num[MAXN];
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read();m=read();
	for (register int i=1;i<=n;i++)
		a[0][i]=read();
	for (register int i=1;i<=n;i++)
		a[1][i]=read();
	for (register int i=1;i<=m;i++)
	{
		opt=read();
		if (opt==1)
		{
			x=read();y=read();z=read();
			a[x][y]=z;
		}	
		else
		if (opt==2)
		{
			l1=read();r1=read();l2=read();r2=read();
			bound=0;
			for (register int p=l1;p<=r1;p++)
			{
				bound++;num[bound]=a[0][p];
			}
			for (register int p=l2;p<=r2;p++)
			{
				bound++;num[bound]=a[1][p];
			}
			sort(num+1,num+bound+1);
			cout << num[(bound+1)/2] << endl;
		}
	} 
	return 0;
}

