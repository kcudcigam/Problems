#include<bits/stdc++.h>
using namespace std;
long long mo=1000000007,n,m,f[301][301];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	read(n);read(m);
	f[1][1]=1;
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=m;j++)
	{
		for(register int k=1;k<i;k++) 
		f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%mo;
		for(register int k=1;k<j;k++)
		f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%mo;
	}
	cout<<f[n][m];
	return 0;
	
}
