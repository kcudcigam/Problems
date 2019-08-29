#include <cstdio>
#include <iostream>

using namespace std;

const int mod=1e9+7;

long long dp[301][301][3];
int n,m;

template <typename T> inline void read(T &n)
{
	n=0;char c;T f=1;
	for (c=getchar();!isdigit(c);c=getchar())
		if (c=='-') 
			f=-1;
	for (;isdigit(c);c=getchar()) 
		n=(n<<1)+(n<<3)+(c^48);
	n*=f;
}

template <typename T> inline void write(T n)
{
	if (n<0)
	{
		putchar('-');
		n=-n;
	}
	if (n>9) write(n/10);
	putchar(n%10+'0');
}

template <typename T> inline void writeln(T n)
{
	write(n);
	puts("");
}

int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	read(n);
	read(m);
	dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=1;
	for (register int i=1;i<=n;++i)
		for (register int j=1;j<=m;++j)
		{
			if (i==1 && j==1)
				continue;
			for (register int k=1;k<i;++k)
				dp[i][j][1]=(dp[i][j][1]+dp[k][j][0]*dp[i-k][j][0]%mod)%mod;
			for (register int k=1;k<j;++k)
				dp[i][j][2]=(dp[i][j][2]+dp[i][k][0]*dp[i][j-k][0]%mod)%mod;
			dp[i][j][0]=(dp[i][j][1]+dp[i][j][2])%mod;	
		}
	writeln(dp[n][m][0]);
	return 0;
}
